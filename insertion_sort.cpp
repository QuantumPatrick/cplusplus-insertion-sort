#include <stdio.h>
#include <vector>
#include <time.h>

std::vector<int> initialize_list() {
  std::vector<int> list_to_sort;
  int random_int;
  for (int i = 0; i < 20; i++) {
    random_int = rand() % 100 + 1;
    list_to_sort.push_back(random_int);
  }

  std::cout << "Initial list: " << std::endl;
  for (int i = 0; i < list_to_sort.size(); i++) {
    std::cout << list_to_sort.at(i) << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  return list_to_sort;
}

void insertion_sort(std::vector<int> list_to_sort) {
  int iterator_position = 0;
  int min_value;
  int min_position;
  int max_value = 0;

  for (int i = 0; i < list_to_sort.size(); i++) {
    if (list_to_sort.at(i) > max_value) {
      max_value = list_to_sort.at(i);
    }
  }

  // FIXME: why does the program lose a value without a '-1'?
  for (int i = 0; i < list_to_sort.size() - 1; i++) {
    min_value = max_value;
    min_position = 0;
    // find minimum value in list
    for (int j = iterator_position; j < list_to_sort.size(); j++) {
      if (list_to_sort.at(j) < min_value) {
        min_value = list_to_sort.at(j);
        min_position = j;
      }
    }
    // insert minimum value at the front of the unsorted portion of the list
    list_to_sort.insert(list_to_sort.begin() + iterator_position, min_value);
    // erases the minimum value from its original position in the list
    list_to_sort.erase(list_to_sort.begin() + min_position + 1);

    // prints every step of the sort to show the process
    // remove block comment to display
    /*for (int i = 0; i < list_to_sort.size(); i++) {
      std::cout << list_to_sort.at(i) << " ";
    }
    std::cout << std::endl;*/
    iterator_position++;
  }

  std::cout << "Final list: " << std::endl;
  for (int i = 0; i < list_to_sort.size(); i++) {
    std::cout << list_to_sort.at(i) << " ";
  }
  std::cout << std::endl;
}

int main(void) {
  srand(time(NULL));
  std::vector<int> list = initialize_list();
  insertion_sort(list);

  return 0;
}
