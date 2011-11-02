/* The LibVMI Library is an introspection library that simplifies access to 
 * memory in a target virtual machine or in a file containing a dump of 
 * a system's physical memory.  LibVMI is based on the XenAccess Library.
 *
 * Copyright 2011 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government
 * retains certain rights in this software.
 *
 * Author: Bryan D. Payne (bpayne@sandia.gov)
 *
 * This file is part of LibVMI.
 *
 * LibVMI is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * LibVMI is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with LibVMI.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "libvmi.h"

void vmi_print_hex (unsigned char *data, unsigned long length)
{
    int i, j, numrows, index;

    numrows = (length+15)>>4;
    
    for (i = 0; i < numrows; ++i){
        /* print the byte count */
        printf("%.8x|  ", i*16);

        /* print the first 8 hex values */
        for (j = 0; j < 8; ++j){
            index = i*16+j;
            if (index < length){
                printf("%.2x ", data[index]);
            }
            else{
                printf("   ");
            }
        }
        printf(" ");

        /* print the second 8 hex values */
        for ( ; j < 16; ++j){
            index = i*16+j;
            if (index < length){
                printf("%.2x ", data[index]);
            }
            else{
                printf("   ");
            }
        }
        printf("  ");

        /* print the ascii values */
        for (j = 0; j < 16; ++j){
            index = i*16+j;
            if (index < length){
                if (isprint((int)data[index])){
                    printf("%c", data[index]);
                }
                else{
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

