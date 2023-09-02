#include <stdio.h>
#include "LinkedList.h"


int main() {
  LinkedList *li = create_list();
  insert_at_beginning(li, 5);
  insert_at_end(li, 10);
  insert_at_beginning(li, 3);
  insert(li, 2, 0);
  insert(li, 11, 100);
  insert(li, 7, 3);
  print_list(li);
  free_list(li);
  return 0;
}
