/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using init_genrand(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)
*/

/*!
 * \file MersenneTwister.cpp
 * \brief Fichier de definition d'une classe permettant de generer des nombres pseudo-aleatoires.
 * \author Antoine Colmard
 * \author Nicolas Prugne
 * \version 0.1
 */

#include "MersenneTwister.h"

/*!
 *  \brief Constructeur parametre
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 *
 *  Initialise le generateur avec une graine passee en parametre.
 *
 *  \param s : un entier non signe permettant d'initialiser le generateur.
 */
MersenneTwister::MersenneTwister(unsigned long s)
{
    m_nMti = N + 1;
    init_genrand(s);
}

/*!
 *  \brief Constructeur parametre
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 *
 *  Initialise le generateur avec un tableau d'entiers passe en parametre.
 *
 *  \param init_key : tableau d'entiers.
 *	\param key_length : taille du tableau.
 */
MersenneTwister::MersenneTwister(unsigned long init_key[], int key_length)
{
    m_nMti = N + 1;
    init_by_array(init_key, key_length);
}

/*!
 *  \brief Constructeur
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 *
 *  Initialise le generateur avec une graine par defaut (5489UL).
 */
MersenneTwister::MersenneTwister()
{
    m_nMti = N + 1;
}

/*!
 *  \brief Destructeur
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 */
MersenneTwister::~MersenneTwister()
{
}

/*!
 *  \brief Methode permettant d'initialiser le generateur avec une graine passee en parametre.
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 *
 * Initilise le tableau m_Mt avec une graine.
 *
 *  \param s : un entier non signe (graine).
 */
void MersenneTwister::init_genrand(unsigned long s)
{
    m_Mt[0] = s & 0xffffffffUL;
    for (m_nMti = 1; m_nMti < N; m_nMti++) {
        m_Mt[m_nMti] = (1812433253UL * (m_Mt[m_nMti - 1] ^ (m_Mt[m_nMti - 1] >> 30)) + m_nMti);
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        m_Mt[m_nMti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */

/*!
 *  \brief Methode permettant d'initialiser le generateur avec un tableau passe en parametre.
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 *
 * Initilise le tableau m_Mt a partir d'un second tableau passe en parametre.
 *
 *  \param init_key : tableau d'entiers.
 *  \param key_length : taille du tableau.
 */
void MersenneTwister::init_by_array(unsigned long init_key[], int key_length)
{
    int i, j, k;
    init_genrand(19650218UL);
    i = 1; j = 0;
    k = (N > key_length ? N : key_length);
    for (; k; k--) {
        m_Mt[i] = (m_Mt[i] ^ ((m_Mt[i - 1] ^ (m_Mt[i - 1] >> 30)) * 1664525UL))
            + init_key[j] + j; /* non linear */
        m_Mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i >= N) { m_Mt[0] = m_Mt[N - 1]; i = 1; }
        if (j >= key_length) j = 0;
    }
    for (k = N - 1; k; k--) {
        m_Mt[i] = (m_Mt[i] ^ ((m_Mt[i - 1] ^ (m_Mt[i - 1] >> 30)) * 1566083941UL))
            - i; /* non linear */
        m_Mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i >= N) { m_Mt[0] = m_Mt[N - 1]; i = 1; }
    }

    m_Mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */
}

/*!
 *  \brief Methode permettant de generer un entier non signe sur 32 bits.
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 */
unsigned long MersenneTwister::genrand_int32(void)
{
    unsigned long y;
    static unsigned long mag01[2] = { 0x0UL, MATRIX_A };
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (m_nMti >= N) { /* generate N words at one time */
        int kk;

        if (m_nMti == N + 1)   /* if init_genrand() has not been called, */
            init_genrand(5489UL); /* a default initial seed is used */

        for (kk = 0; kk < N - M; kk++) {
            y = (m_Mt[kk] & UPPER_MASK) | (m_Mt[kk + 1] & LOWER_MASK);
            m_Mt[kk] = m_Mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (; kk < N - 1; kk++) {
            y = (m_Mt[kk] & UPPER_MASK) | (m_Mt[kk + 1] & LOWER_MASK);
            m_Mt[kk] = m_Mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (m_Mt[N - 1] & UPPER_MASK) | (m_Mt[0] & LOWER_MASK);
        m_Mt[N - 1] = m_Mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        m_nMti = 0;
    }

    y = m_Mt[m_nMti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

/* generates a random number on [0,0x7fffffff]-interval */
/*!
 *  \brief Methode permettant de generer un entier non signe sur 31 bits.
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 */
long MersenneTwister::genrand_int31(void)
{
    return (long)(genrand_int32() >> 1);
}

/* generates a random number on [0,1]-real-interval */
/*!
 *  \brief Methode permettant de generer un reel compris dans l'intervalle [0, 1].
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 */
double MersenneTwister::genrand_real1(void)
{
    return genrand_int32()*(1.0 / 4294967295.0);
    /* divided by 2^32-1 */
}

/* generates a random number on [0,1)-real-interval */
/*!
 *  \brief Methode permettant de generer un reel compris dans l'intervalle [0, 1).
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 */
double MersenneTwister::genrand_real2(void)
{
    return genrand_int32()*(1.0 / 4294967296.0);
    /* divided by 2^32 */
}

/* generates a random number on (0,1)-real-interval */
/*!
 *  \brief Methode permettant de generer un reel compris dans l'intervalle (0, 1).
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 */
double MersenneTwister::genrand_real3(void)
{
    return (((double)genrand_int32()) + 0.5)*(1.0 / 4294967296.0);
    /* divided by 2^32 */
}

/* generates a random number on [0,1) with 53-bit resolution*/
/*!
 *  \brief Methode permettant de generer un reel compris dans l'intervalle (0, 1) sur 53 bits.
 *	\author Takuji Nishimura
 *	\author Makoto Matsumoto
 */
double MersenneTwister::genrand_res53(void)
{
    unsigned long a = genrand_int32() >> 5, b = genrand_int32() >> 6;
    return(a*67108864.0 + b)*(1.0 / 9007199254740992.0);
}
