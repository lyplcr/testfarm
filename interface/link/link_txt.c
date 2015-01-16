/****************************************************************************/
/* TestFarm                                                                 */
/* Interface logical link management - Text data source                     */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 06-APR-2007                                                    */
/****************************************************************************/

/*
 * $Revision: 733 $
 * $Date: 2007-09-22 21:45:49 +0200 (sam., 22 sept. 2007) $
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <glib.h>

#include "link.h"
#include "link_txt.h"


static void link_txt_unref(link_src_txt_t *src_txt)
{
  g_list_foreach(src_txt->sources, (GFunc) free, NULL);
  g_list_free(src_txt->sources);
  src_txt->sources = NULL;
}


static int link_txt_parse(link_src_txt_t *src_txt, int argc, char **argv)
{
  int i;

  link_txt_unref(src_txt);

  for (i = 0; i < argc; i++) {
    char *item = strdup(argv[i]);
    src_txt->sources = g_list_append(src_txt->sources, item);
  }

  return 0;
}


static void link_txt_clear(link_src_txt_t *src_txt)
{
  src_txt->sources = NULL;
}


static void link_txt_show_item(char *item)
{
  printf(" %s", item);
}


static void link_txt_show(link_src_txt_t *src_txt)
{
  g_list_foreach(src_txt->sources, (GFunc) link_txt_show_item, NULL);
}


int link_txt_attached(link_src_txt_t *src_txt, char *id)
{
  GList *l = g_list_find_custom(src_txt->sources, id, (GCompareFunc) strcmp);
  return (l != NULL);
}


static int link_txt_send_data(link_src_bin_t *bin, char **argv, void **pbuf)
{
  char *buf = NULL;
  int size = 0;
  int len = 0;
  int i;

  for (i = 0; argv[i] != NULL; i++) {
    char *str2 = argv[i];
    int len2 = strlen(str2);

    size = len + len2 + 3;
    buf = realloc(buf, size);

    if ( i > 0 ) {
      buf[len++] = ' ';
    }

    strcpy(buf+len, str2);
    len += len2;
  }

  buf[len++] = '\n';

  if ( pbuf != NULL )
    *pbuf = buf;  

  return len;
}


int link_txt_init(void)
{
  link_src_desc.help_str0 =
    "<source> ...";
  link_src_desc.help_str1 =
    "  Data flow input is sourced from <source>. Multiple sources are allowed.\n";
  link_src_desc.parse = (void *) link_txt_parse;
  link_src_desc.clear = (void *) link_txt_clear;
  link_src_desc.show = (void *) link_txt_show;
  link_src_desc.unref = (void *) link_txt_unref;
  link_src_desc.send_data = (void *) link_txt_send_data;

  return 0;
}
