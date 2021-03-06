#include <TH/THBlas.h>
#include <c10/core/ScalarType.h>

// This header file shouldn't be anything permanent; it's just a temporary
// dumping ground to help you get access to utilities in THBlas.h via templates,
// rather than by name directly.  Someone should figure out a reasonable way to
// rewrite these in more idiomatic ATen and move it into ATen proper.

template<typename T>
inline void THBlas_axpy(int64_t n, T a, T *x, int64_t incx, T *y, int64_t incy);

#define AXPY_SPECIALIZATION(ctype,name,_1) \
  template<> \
  inline void THBlas_axpy<ctype>(int64_t n, ctype a, ctype *x, int64_t incx, \
                   ctype *y, int64_t incy) { \
    TH ## name ## Blas_axpy(n, a, x, incx, y, incy); \
  }

AT_FORALL_SCALAR_TYPES_EXCEPT_HALF_AND_QINT(AXPY_SPECIALIZATION)


template<typename T>
inline void THBlas_copy(int64_t n, T *x, int64_t incx, T *y, int64_t incy);

#define COPY_SPECIALIZATION(ctype,name,_1) \
  template<> \
  inline void THBlas_copy<ctype>(int64_t n, ctype *x, int64_t incx, \
                   ctype *y, int64_t incy) { \
    TH ## name ## Blas_copy(n, x, incx, y, incy); \
  }

AT_FORALL_SCALAR_TYPES_EXCEPT_HALF_AND_QINT(COPY_SPECIALIZATION)

template<typename T>
inline T THBlas_dot(int64_t n, T *x, int64_t incx, T *y, int64_t incy);

#define DOT_SPECIALIZATION(ctype,name,_1) \
  template<> \
  inline ctype THBlas_dot<ctype>(int64_t n, ctype *x, int64_t incx, ctype *y, int64_t incy) { \
    return TH ## name ## Blas_dot(n, x, incx, y, incy); \
  }

AT_FORALL_SCALAR_TYPES_EXCEPT_HALF_AND_QINT(DOT_SPECIALIZATION)
