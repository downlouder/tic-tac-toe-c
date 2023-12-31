#include <stdio.h>
#include <conio.h>  //getch()
#include <stdlib.h> //system()

char arr[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void showBoard();
int checkForWin();

int main()
{
  int response;
  do
  {
    int player = 1, choice, i;
    char mark; // X or O

    do
    {
      showBoard();
      player = (player % 2) ? 1 : 2;
      printf("Player 1 plays X \t Player 2 plays O\n");
      printf("Player %d turn: ", player);
      scanf("%d", &choice);
      mark = (player == 1) ? 'X' : 'O';

      if (choice == 1 && arr[1] == '1')
        arr[1] = mark;
      else if (choice == 2 && arr[2] == '2')
        arr[2] = mark;
      else if (choice == 3 && arr[3] == '3')
        arr[3] = mark;
      else if (choice == 4 && arr[4] == '4')
        arr[4] = mark;
      else if (choice == 5 && arr[5] == '5')
        arr[5] = mark;
      else if (choice == 6 && arr[6] == '6')
        arr[6] = mark;
      else if (choice == 7 && arr[7] == '7')
        arr[7] = mark;
      else if (choice == 8 && arr[8] == '8')
        arr[8] = mark;
      else if (choice == 9 && arr[9] == '9')
        arr[9] = mark;
      else
      {
        printf("Invalid value\n");
        player--;
        getch();
      }

      i = checkForWin();
      player++;
    } while (i == -1);
    showBoard();

    if (i == 1)
    {
      printf("Player %d Won\n", player - 1);
    }
    else
    {
      printf("Game Draw\n");
    }
    printf("\n1. Play Again\n2. Exit \n");
    scanf("%d", &response);
    if (response == 1)
    {
      arr[1] = '1', arr[2] = '2', arr[3] = '3', arr[4] = '4', arr[5] = '5', arr[6] = '6', arr[7] = '7', arr[8] = '8', arr[9] = '9';
    }
    else if (response == 2)
      break;
  } while (response);

  return 0;
}

void showBoard()
{
  system("cls");
  printf("\n      TIC TAC TOE\n\n");
  printf("       |       |       \n");
  printf("   %c   |   %c   |   %c   \n", arr[1], arr[2], arr[3]);
  printf("       |       |       \n");
  printf("-------|-------|-------\n");
  printf("       |       |       \n");
  printf("   %c   |   %c   |   %c   \n", arr[4], arr[5], arr[6]);
  printf("       |       |       \n");
  printf("-------|-------|-------\n");
  printf("       |       |       \n");
  printf("   %c   |   %c   |   %c   \n", arr[7], arr[8], arr[9]);
  printf("       |       |       \n");
}

int checkForWin()
{
  if (arr[1] == arr[2] && arr[2] == arr[3])
    return 1;
  else if (arr[4] == arr[5] && arr[5] == arr[6])
    return 1;
  else if (arr[7] == arr[8] && arr[8] == arr[9])
    return 1;
  else if (arr[1] == arr[4] && arr[4] == arr[7])
    return 1;
  else if (arr[2] == arr[5] && arr[5] == arr[8])
    return 1;
  else if (arr[3] == arr[6] && arr[6] == arr[9])
    return 1;
  else if (arr[1] == arr[5] && arr[5] == arr[9])
    return 1;
  else if (arr[3] == arr[5] && arr[5] == arr[7])
    return 1;
  else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
    return 0;
  else
    return -1;
}