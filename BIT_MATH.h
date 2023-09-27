#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(REG,BIT_NO)     (REG |= (1 << BIT_NO))
#define CLR_BIT(REG,BIT_NO)     (REG &= (~(1 << BIT_NO)))
#define GET_BIT(REG,BIT_NO)     ((REG >> BIT_NO) & 1)
#define TOGGLE_BIT(REG,BIT_NO)  (REG ^= (1 << BIT_NO))


#endif

// BIT_MATH.h