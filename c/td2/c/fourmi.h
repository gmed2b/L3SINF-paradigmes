// Mehdi Ghoulam TD2-C

#ifndef FOURMI_H
#define FOURMI_H

typedef struct fourmi {
  int x;
  int y;
  int dx;
  int dy;
  int color;
  char sym;
} fourmi;

fourmi *init_fourmi();

void avance(fourmi *fourmi);

void affiche_p(fourmi *fourmi);

void affiche_c(fourmi *fourmi);

#endif
