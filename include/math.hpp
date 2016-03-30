#ifndef S3D_MATH_HPP
#define S3D_MATH_HPP

#include "cppfn.h"
#include "mat.h"
#include "vec.h"

cppfn void s3d_translate(s3d_fmat4 mat, const s3d_fvec3 val);
cppfn void s3d_scale(s3d_fmat4 mat, const s3d_fvec3 val);
cppfn void s3d_axis_rot(s3d_fmat4 out, float angle, const s3d_fvec3 axis);
cppfn void s3d_euler_rot(s3d_fmat4 mat, s3d_fvec3 rot);

#endif
