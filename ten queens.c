#include<stdio.h>

char check(int i, char q[], char x) {
  int flag = -1;
  char h;

  if (x > '9')
    flag = -2;

  for (int j = 0; j < i && x <= '9'; ++j)
  {
    if (x == q[j] || x - q[j] == i - j || x - q[j] == -1 * (i - j))
    {
      flag = x - 48;
      flag = check(i, q, x + 1);
      break;
    }
  }

  if (flag == -2)
    return 'A';
  else if (flag != -1)
    return flag;
  else
    return x;
}

int gen(int i, char q[], char x) {
  char z = '0', h;
  int j = 0, po = 0;

  while ((po >= 0))
  {
    for (; j <= 9 && j >= 0; ++j)
    {

      q[j] = check(j, q, z);

      if (q[j] == 'A') {
        j -= 2;
        if (q[j + 1] == '9')
          --j;
        z = q[j + 1] + 1;

        if (q[0] == '9' && j == 0 && z >= '8')
          j = -2;
      }
     else if (q[j] >= '0' && q[j] <= '9')
        z = '0';
    }


    if (j >= 0) {
      ++po;
      printf("%d. %s\n", po, q);
    } else
      return po;

    for (j = 8; q[j] == '9' && j >= 0; --j);
    z = q[j] + 1;
  }

}

int main() {

  char q[10] = {
    '-',
    '-',
    '-',
    '-',
    '-',
    '-',
    '-',
    '-',
    '-',
    '-'
  };
  printf("\n\n>>>>>>>>>%d<<<<<<<<<<<<", gen(0, q, '0'));

  return 0;
}