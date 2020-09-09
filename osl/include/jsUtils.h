#include "stdosl.h"


/*
    Check for each of the per-channel parameters of an input color/point/vector/normal if they are connected
    to an upstream node in the shading network, and, if so, we use that value instead of the one coming from
    the color/point/vector/normal parameter.
*/
color getComposedColor(color i_color_rgb, float i_color_r, float i_color_g, float i_color_b)
{
    color o_color_rgb = i_color_rgb;

    if (isconnected(i_color_r))
        o_color_rgb[0] = i_color_r;
    if (isconnected(i_color_g))
        o_color_rgb[1] = i_color_g;
    if (isconnected(i_color_b))
        o_color_rgb[2] = i_color_b;

    return o_color_rgb;
}


point getComposedPoint(point i_point_xyz, float i_point_x, float i_point_y, float i_point_z)
{
    point o_point_xyz = i_point_xyz;

    if (isconnected(i_point_x))
        o_point_xyz[0] = i_point_x;
    if (isconnected(i_point_y))
        o_point_xyz[1] = i_point_y;
    if (isconnected(i_point_z))
        o_point_xyz[2] = i_point_z;

    return o_point_xyz;
}


vector getComposedVector(vector i_vector_xyz, float i_vector_x, float i_vector_y, float i_vector_z)
{
    vector o_vector_xyz = i_vector_xyz;

    if (isconnected(i_vector_x))
        o_vector_xyz[0] = i_vector_x;
    if (isconnected(i_vector_y))
        o_vector_xyz[1] = i_vector_y;
    if (isconnected(i_vector_z))
        o_vector_xyz[2] = i_vector_z;

    return o_vector_xyz;
}


normal getComposedNormal(normal i_normal_xyz, float o_normal_x, float o_normal_y, float o_normal_z)
{
    normal o_normal_xyz = i_normal_xyz;

    if (isconnected(o_normal_x))
        o_normal_xyz[0] = o_normal_x;
    if (isconnected(o_normal_y))
        o_normal_xyz[1] = o_normal_y;
    if (isconnected(o_normal_z))
        o_normal_xyz[2] = o_normal_z;

    return o_normal_xyz;
}


float getFresnel(normal i_normal, float i_ior, int i_mode)
{
    float o_fresnel_reflect = 0.0;
    float o_fresnel_refract = 0.0;

    // We assume that the first medium is air, making the function not suitable for nested dielectrics.
    fresnel(
        normalize(I),
        i_normal,
        (1.0 / i_ior),
        o_fresnel_reflect,
        o_fresnel_refract
    );

    return (i_mode == 0 ? o_fresnel_reflect : o_fresnel_refract);
}


float getFractional(float i_float)
{
    if (i_float >= 0)
        return i_float - floor(i_float);
    else
        return i_float - ceil(i_float);
}


float getBias(float i_float, float i_bias_rgb)
{
    float bias_rgb = clamp(i_bias_rgb, 0.0001, 0.9999);
    float o_bias_rgb = i_float / ((1.0 / bias_rgb - 2.0) * (1.0 - i_float) + 1.0);

    return clamp(o_bias_rgb, 0.0, 1.0);
}


float getGain(float i_float, float i_gain_rgb)
{
    float gain_rgb = clamp(i_gain_rgb, 0.0001, 0.9999);
    float o_gain_rgb;

    if (i_float < 0.5)
        o_gain_rgb = i_float / ((1.0 / gain_rgb - 2.0) * (1.0 - 2.0 * i_float) + 1.0);
    else
        o_gain_rgb = ((1.0 / gain_rgb - 2.0) * (1.0 - 2.0 * i_float) - i_float) /
            ((1.0 / gain_rgb - 2.0) * (1.0 - 2.0 * i_float) - 1.0);

    return clamp(o_gain_rgb, 0.0, 1.0);
}
