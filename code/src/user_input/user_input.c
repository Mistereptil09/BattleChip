//
// Created by narbo on 26/09/2025.
//
#include <stdio.h>
#include <ctype.h>
#include "user_input.h"

char user_input(){
   char input;
   do {
      scanf("%c", &input);
   } while(!isalnum(input));

   return input;
}