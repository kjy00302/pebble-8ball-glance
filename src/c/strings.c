#include "strings.h"

// Magic 8 Ball strings from Wikipedia
static const char *strings[] = {
  "It is certain",
  "It is decidedly so",
  "Without a doubt",
  "Yes definitely",
  "You may rely on it",
  "As I see it, yes",
  "Most likely",
  "Outlook good",
  "Yes",
  "Signs point to yes",

  "Reply hazy, try again",
  "Ask again later",
  "Better not tell you now",
  "Cannot predict now",
  "Concentrate and ask again",

  "Don't count on it",
  "My reply is no",
  "My sources say no",
  "Outlook not so good",
  "Very doubtful"
};

int strings_get_cnt(void) {
  return sizeof(strings) / sizeof(char*);
}

const char *strings_get_str(int idx) {
  return strings[idx];
}
