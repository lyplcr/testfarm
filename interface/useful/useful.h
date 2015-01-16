/****************************************************************************/
/* TestFarm                                                                 */
/* Miscellaneous useful functions                                           */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 17-AUG-1999                                                    */
/****************************************************************************/

/*
 * $Revision: 1151 $
 * $Date: 2010-06-05 19:45:01 +0200 (sam., 05 juin 2010) $
 */

#ifndef __USEFUL_H
#define __USEFUL_H

#include <stdio.h>

/* Integer ceiling division */
#define CEIL_DIV(a,b) (((a)+(b)-1) / (b))

/* Stringification */
#define STRINGIFY(a) _STRINGIFY(a)
#define _STRINGIFY(a) #a

/* NUL character (ASCII 0) */
#ifndef NUL
#define NUL '\0'
#endif


/* strcleanup(): replace non-printable characters with spaces.
 *   INPUT:  str = characters string to clean up.
 *   OUTPUT: pointer to the input string.
 */
extern char *strcleanup(char *str);


/* strskip_spaces(): skip leading spaces of a characters string.
 * strskip_chars(): skip leading non-spaces of a characters string.
 *   INPUTS: str = characters string to process.
 *   OUPUT:  pointer to the new beginning of the string.
 */
extern char *strskip_spaces(char *str);
extern char *strskip_chars(char *str);


/* strupper(): convert characters string to uppercase.
 *  INPUT:  str = string to convert.
 *  OUTPUT: pointer to the input string.
 */
extern char *strupper(char *str);


/* strread(): equivalent to fgets(), but by invoking the read() system call.
 *   INPUT:  fd = file descriptor data come from.
 *           s = target buffer.
 *           size = target buffer size.
 *   OUTPUT: number of character read, including the trailing LF.
 *           In addition, a NUL character is put after the trailing LF, but
 *           not counted in this returned value.
 */
extern int strread(int fd, char *s, int size);


/* strtimestamp(): build a text-formatted time stamp 
 *   INPUT:  none
 *   OUTPUT: pointer on a static buffer containing the time stamp
 */
extern char *strtimestamp(void);


/* sleep_ms(): sleep for some milliseconds
 *   INPUT:  msec = time duration in milliseconds.
 *   OUTPUT: none. Exits when the input time is elapsed.
 */
extern void sleep_ms(long msec);


/* fgets2(): get a line from text file, while (re)allocating buffer accordingly
 *   INPUT:  f = FILE stream to read from.
 *           buf = address of the line storage buffer pointer.
 *           size = address of the line storage buffer size.
 *   OUTPUT: The length of the loaded line, on -1 on error.
 *           After usage, the buffer should be freed if not NULL.
 */
extern int fgets2(FILE *f, char **pbuf, int *psize);


/* strxml(): convert an XML string to raw ASCII character encoding
 *   INPUT:  str = string to convert
 *   OUTPUT: pointer to the input string
 */
extern char *strxml(char *str);

#endif /* __USEFUL_H */
