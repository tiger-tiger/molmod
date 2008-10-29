// MolModExt implements a few number crunching routines for the molmod package in C.
// Copyright (C) 2007 - 2008 Toon Verstraelen <Toon.Verstraelen@UGent.be>
//
// This file is part of MolModExt.
//
// MolModExt is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
//
// MolModExt is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>
//
// --


void graphs_floyd_warshall(int n, int* dm) {
  int i, j, k, d_ik, d_kj, d_orig, d_new;

  for (k=0; k<n; k++) {
    for (j=0; j<n; j++) {
      if (j==k) continue;
      for (i=0; i<j; i++) {
        if (i==k) continue;
        d_ik = dm[i*n+k];
        d_kj = dm[k*n+j];
        if (d_ik > 0 && d_kj > 0) {
          d_orig = dm[i*n+j];
          d_new = d_ik+d_kj;
          if (d_new < d_orig || d_orig == 0) {
            dm[i*n+j] = d_new;
            dm[j*n+i] = d_new;
          }
        }
      }
    }
  }
}