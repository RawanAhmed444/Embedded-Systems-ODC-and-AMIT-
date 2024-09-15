/*
 * BIT_MATH.h
 *
 * Created: 9/10/2024 7:18:42 PM
 *  Author: RAWAN
 */


#ifndef  _BIT_MATH_H
#define  _BIT_MATH_H


#define SET_BIT(REG,BIT)     (REG|=1<<BIT)
#define CLR_BIT(REG,BIT)     (REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)  (REG^=1<<BIT)
#define GET_BIT(REG,BIT)     ((REG>>BIT)&1)


#endif