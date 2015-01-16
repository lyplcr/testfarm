/****************************************************************************/
/* TestFarm                                                                 */
/* String cleanup utility                                                   */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 17-AUG-1999                                                    */
/****************************************************************************/

/*
 * $Revision: 1181 $
 * $Date: 2010-07-11 18:22:02 +0200 (dim., 11 juil. 2010) $
 */

#include "useful.h"

char *strcleanup(char *s)
{
  char *p = s;

  while ( *p != NUL ) {
    if ( *p < ' ' )
      *p = ' ';
    p++;
  }

  while (p > s) {
	  p--;
	  if (*p != ' ')
		  break;
	  *p = '\0';
  }

  return s;
}
