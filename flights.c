#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct kq_airline {
  char passport[6];
  char name[15];
  char destination[15];
  int seat_num;
  char email[15];
  struct kq_airline *next;
} kq_airline;

kq_airline *head = NULL;

void reserve(int x) {
  kq_airline *new_passenger = (kq_airline *)malloc(sizeof(kq_airline));

  printf("\n\tEnter your passport number: ");
  scanf("%s", new_passenger->passport);

  printf("\n\tEnter your name: ");
  scanf("%s", new_passenger->name);

  printf("\n\tEnter your email address: ");
  scanf("%s", new_passenger->email);

  printf("\n\tEnter your destination: ");
  scanf("%s", new_passenger->destination);

  new_passenger->seat_num = x;
  new_passenger->next = head;

  head = new_passenger;

  printf("\n\tSEAT BOOKING SUCCESSFUL!");
  printf("\n\tYour seat number is: Seat A-%d", x);
}

void cancel() {
  char passport[6];

  printf("\n\tEnter your passport number to delete record: ");
  scanf("%s", passport);

  kq_airline *current = head;
  kq_airline *previous = NULL;

  while (current) {
    if (strcmp(current->passport, passport) == 0) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }

      free(current);
      printf("\n\tRECORD DELETED");
      return;
    }

    previous = current;
    current = current->next;
  }

  printf("\n\tPassport number not found");
}

void display() {
  kq_airline *current = head;

  while (current) {
    printf("\n\n Passport Number: %-6s", current->passport);
    printf("\n Name: %-15s", current->name);
    printf("\n Email address: %-20s", current->email);
    printf("\n Seat number: A-%d", current->seat_num);
    printf("\n Destination: %-15s", current->destination);
    printf("\n++*======================================*++");

    current = current->next;
  }
}

int main() {
  int choice;
  int num = 1;

  do {
    printf("\n\n\t\tWELCOME TO KENYA AIRWAYS");

    printf("\n\n\t\tPlease enter your choice from below (1 or 2)");
    printf("\n\n\t\t1. Reservation");
    printf("\n\n\t\t2. Cancel");
    printf("\n\n\t\t3. Display Records\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        reserve(num);
        num++;
        break;
      case 2:
        cancel();
        break;
      case 3:
        display();
        break;
      default:
        printf("\n\n\tINVALID CHOICE");
    }
  } while (choice != 3);

  return 0;
}
