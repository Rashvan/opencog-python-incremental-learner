/*
 * opencog/embodiment/AGISimSim/shared/include/vsscanf.cpp
 *
 * Copyright (C) 2002-2007 Novamente LLC
 * All Rights Reserved
 *
 * Written by Ari A. Heljakka
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "vsscanf.h"
#include <stdio.h>
#include <ctype.h>

enum {NORMAL_TYPE,LONG,SHORT};


int vsscanf( char *buf, char *format, va_list argp ) 
{ 
char *fmtp; 
        char *bufp; 
bool suppress; 
int mytype, width, n, k = 0; 
char lastchar; 


bufp = buf; 


for (fmtp = format; *fmtp; fmtp++) 
{ if (*fmtp == '%') 
{ mytype = NORMAL_TYPE; 
suppress = false; 
width = 0; 
lastchar = ' '; 
} 
else if (*fmtp == '*') 
suppress = true; 
else if (isspace(*fmtp)); 
else if (isdigit(*fmtp)) 
{ if (lastchar != '.') 
{ width *= 10; 
width += (*fmtp - '0'); 
} 
} 
else if (*fmtp == 'l' || *fmtp == 'L') 
mytype = LONG; 
else if (*fmtp == 'h') 
mytype = SHORT; 
else if (*fmtp == 'i' || *fmtp == 'd') 
{ if (suppress) 
bufp = Advance(bufp); 
else if (mytype == SHORT) 
{ k+=sscanf(bufp,"%hd%n",va_arg(argp,short*),&n); 
bufp+=n; 
               } 
               else if (mytype == LONG) 
{ k+=sscanf(bufp,"%ld%n",va_arg(argp,long*),&n); 
bufp+=n; 
} 
else 
{ k+=sscanf(bufp,"%d%n",va_arg(argp, int*),&n); 
bufp+=n; 
} 
} 
else if (*fmtp == 'f') 
{ if (suppress) 
bufp = Advance(bufp); 
else if (mytype == LONG) 
{ k+=sscanf(bufp,"%f%n",va_arg(argp, double*),&n); 
bufp+=n; 
} 
else 
{ k+=sscanf(bufp,"%f%n",va_arg(argp, float*),&n); 
bufp+=n; 
} 
} 
else if (*fmtp == 's') 
{ if (suppress) 
bufp = Advance(bufp); 
else { 
k+=sscanf(bufp,"%s%n",va_arg(argp, char*),&n); 
bufp+=n; 
} 
} 
else if (*fmtp == 'c') 
{ if (!suppress) 
{ k+=sscanf(bufp,"%c%n",va_arg(argp, char*),&n); 
bufp+=n; 
} 
               else bufp++; 
} 
else lastchar = *fmtp; 
} /* for */ 
return k; 
} /* vsscanf clone */ 


static char *Advance( char *bufp ) 
{ 
        char *new_bufp = bufp; 


/* Skip over nonwhite SPACE */ 
while ((*new_bufp != ' ') && (*new_bufp != '\t') && 
(*new_bufp != '\n') && (*new_bufp != '\0')) 
new_bufp++; 


/* Skip white SPACE */ 
while ((*new_bufp == ' ') || (*new_bufp == '\t') || 
(*new_bufp == '\n') || (*new_bufp == '\0')) 
new_bufp++; 


return new_bufp; 
} /* Advance */ 

