#include<cstdio>
#include<cstdlib>

int main()
{
  size_t last_index = 0;
  char *p = (char *)malloc(1000005 * sizeof(char));
  char line2[1000005];

  scanf("%s", p);

  for(;*p != '\0'; ++p) {
    if(line2[last_index - 1] == *p) {
      last_index--;
    } else {
      line2[last_index] = *p;
      last_index++;
    }
  }

  char *q = line2;
  for(;last_index; --last_index, q++) putchar(*q);

  printf("\n");

  return 0;
}
