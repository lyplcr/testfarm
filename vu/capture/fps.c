/****************************************************************************/
/* TestFarm Virtual User                                                    */
/* Video Frame Rate statistics                                              */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 04-MAY-2007                                                    */
/****************************************************************************/

/*
 * $Revision: 835 $
 * $Date: 2007-12-04 19:33:15 +0100 (mar., 04 déc. 2007) $
 */

#include <string.h>

#include "fps.h"


void fps_init(fps_t *fps)
{
  fps->t0 = 0;
  memset(fps->nframes, 0, sizeof(fps->nframes));
}


void fps_update(fps_t *fps, unsigned long long tstamp)
{
  if ( fps->t0 > 0 ) {
    unsigned long long dt = (tstamp - fps->t0);
    unsigned long rate = 1000000ULL / dt;

    if ( rate < 1 )
      rate = 1;
    if ( rate > FPS_NFRAMES )
      rate = FPS_NFRAMES;
    (fps->nframes[rate-1])++;
  }

  fps->t0 = tstamp;
}


unsigned long fps_compute(fps_t *fps)
{
  unsigned long fps_max_v[4];
  int fps_max_i[4];
  unsigned long total;
  int i, ii;
  unsigned long long result;

  for (ii = 0; ii < 4; ii++) {
    fps_max_v[ii] = 0;
    fps_max_i[ii] = -1;
  }

  for (i = 0; i < FPS_NFRAMES; i++) {
    unsigned long rate = fps->nframes[i];

    if ( rate > 0 ) {
      unsigned long min = (unsigned long) -1;
      int min_ii = 0;

      for (ii = 0; ii < 4; ii++) {
	unsigned long value = fps_max_v[ii];

	if ( value < min ) {
	  min_ii = ii;
	  min = value;
	}
      }

      if ( rate > fps_max_v[min_ii] ) {
	fps_max_v[min_ii] = rate;
	fps_max_i[min_ii] = i;
      }
    }
  }

  total = 0;
  result = 0;
  for (ii = 0; ii < 4; ii++) {
    total += fps_max_v[ii];
    result += (fps_max_i[ii]+1) * fps_max_v[ii];
  }

  return (total > 0) ? (result / total) : 0;
}
