#include <stdio.h>
#include <stdlib.h>

#include "cgiu.h"
#include "proc.h"

#define  DEBUG 1

void exitfail()
{
  print_html_tail(); 
  exit(0);
}

int main(int argc, char *argv[])
{
  int x,m;
  char *qs;
  entry *entries;
    
  int n;
  char **list,**urls;
  
  /* r�cup�ration de la cha�ne de param�tres */
  qs = get_query_string(argc,argv);

  /* r�cup�ration des couples (nom,valeur) */
  entries = get_entries(qs,&m);

  /* �mission de l'ent�te */
  print_html_head("R&eacute;sultat");

  /* affichage �ventuel des informations de debug */
  if (DEBUG) print_debug_query(entries,m,qs,argc,argv);

  /* lecture de la liste des images */
  list = readList("/u/q/quenotg/HMUL8R6A/PROJET/test/list.txt",&n);
  if (list == NULL) {printf("Failed to read %s file.\n","list.txt"); exitfail();}
  if (DEBUG) printf("Read list, %d images.<BR>\n",n);
  
  /* lecture des urls des images */
  urls = readList("/u/q/quenotg/HMUL8R6A/PROJET/test/urls.txt",&n);
  if (list == NULL) {printf("Failed to read %s file.\n","list.txt"); exitfail();}
  if (DEBUG) printf("Read list, %d images.<BR>\n",n);
  
  /* �mission de la fin de corps et de document */
  print_html_tail();
    
  exit(0);
}
