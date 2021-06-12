#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICIPANTS 100
#define MAX_TEAMS 100

long long int ids[MAX_PARTICIPANTS];
int bets[MAX_PARTICIPANTS];
int n_participants;

int teams[MAX_TEAMS];
int n_teams;

void add_team() { n_teams++; }

int execute() {
  int winner = 0;

  for (int i = 0; i < n_teams; i++) {
    for (int j = i + 1; j < n_teams; j++) {
      if (rand() % 2 == 1) {
        teams[j] += 1;
      } else {
        teams[i] += 1;
      }
    }
  }

  for (int i = 0; i < n_teams; i++) {
    if (teams[winner] < teams[i]) {
      winner = i;
    }
  }

  return winner;
}

int vote_for_winner(long long int id, int bet) {
  if (id >= 1000ll * 1000ll * 1000ll * 10ll) {
    return -1;
  }

  int count = 0;
  for (int i = 0; i < n_participants; i++) {
    if (ids[i] == id) {
      count++;
    }
  }

  if (count >= 2) {
    return -1;
  }

  ids[n_participants] = id;
  bets[n_participants] = bet;

  n_participants++;

  return 0;
}

int main() {
  srand(time(NULL));

  while (1) {
    printf("Welcome to our simulator [n_participants: %d] [n_teams: %d]\n",
           n_participants, n_teams);
    printf("\n");
    printf("1) Add Team\n");
    printf("2) Vote for a Winner\n");
    printf("3) Execute simulation and report a winner\n");

    int choice;
    long long int id;
    int bet;
    int winner;

    scanf("%d", &choice);

    switch (choice) {
    case 1:
      add_team();
      break;
    case 2:
      printf("ID: ");
      scanf("%lld", &id);
      printf("Bet: ");
      scanf("%d", &bet);

      if (vote_for_winner(id, bet) < 0) {
        printf("insertion failed\n");
      } else {
        printf("insertion success\n");
      }
      break;
    case 3:
      winner = execute();
      printf("team %d is a winner\n", winner);

      for (int i = 0; i < n_teams; i++) {
        printf("teams[%d]: %d\n", i, teams[i]);
      }
      for (int i = 0; i < n_participants; i++) {
        if (winner == bets[i]) {
          printf("%010lld win\n", ids[i]);
        }
      }
      return 0;
    default:
      printf("invalid choice\n");
    }
  }
}
