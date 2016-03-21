#include <memory>
#include <vector>
#include <thread>
#include <iostream>
#include <random>
#include <chrono>
#include <unordered_map>

#include "short_alloc.h"

using namespace std;

int mostFrequentNumber(const vector<int>& input)
{
   using LocalAlloc = short_alloc<pair<const int, int>, 100'000, 4>;
   using LocalUnorderedMap = std::unordered_map<int, int, hash<int>, equal_to<int>, LocalAlloc>;
   LocalAlloc::arena_type arena;
   LocalUnorderedMap map(arena);

   // 1500ms
   // std::unordered_map<int, int> map;
   // map.reserve(input.size());

   int max_count = 0;
   int max_number = 0;

   for (const auto& number : input)
   {
      // Emplaces {number, 0} pair if the number is not yet in the map.
      // Returns pair {iterator, bool}.
      auto emplace_result = map.try_emplace(number, 0);

      // Increase the counter of occurences in the map.
      auto count = ++(emplace_result.first->second);

      if (count > max_count)
      {
         max_count = count;
         max_number = number;
      }
   }

   return max_number;
}

vector<int> mostFrequentNumbers(const vector<vector<int>>& inputs)
{
   vector<int> output;
   output.reserve(inputs.size());

   for (const auto& input : inputs)
   {
      output.push_back(mostFrequentNumber(input));
   }

   return output;
}

int main()
{
   const int n_threads = 8;
   const int n_inputs = 1000;
   const int n_elements_per_input = 10'000;
   const int random_seed = 42;

   vector<vector<int>> inputs;

   mt19937 e1(random_seed);
   uniform_int_distribution<int> uniform_dist(1, n_elements_per_input);

   for (int i = 0; i < n_inputs; i++)
   {
      vector<int> v;
      v.reserve(n_elements_per_input);

      for (size_t i = 0; i < n_elements_per_input; i++)
      {
         v.push_back(uniform_dist(e1));
      }

      inputs.push_back(move(v));
   }

   cout << "Random inputs generated, starting work." << endl;

   vector<thread> threads;
   for (int i = 0; i < n_threads; i++)
   {
      auto workItem = [&inputs]
      {
         using namespace chrono;

         auto tBegin = steady_clock::now();
         auto output = mostFrequentNumbers(inputs);
         auto tEnd = steady_clock::now();
         cout << "Work done in " << duration_cast<milliseconds>(tEnd - tBegin).count() << "ms" << endl;
      };

      threads.emplace_back(workItem);
   }

   for (auto& thread : threads)
   {
      thread.join();
   }

   return 0;
}

