3delight-osl-collection
=======================

Collection of OSL shaders for the 3Delight renderer.

Materials
=========

* jsConstant
  * Opacity:
    * Camera
    * Shadow
  * (No) Indirect
* jsVolume
  * Density
  * Anisotropy
  * Transparency
  * Emission:
    * Artistic (Color)
    * Physical (Blackbody)

Lobes
-----

* jsLobeAbsorption
  * Density
* **TODO:** jsLobeCoat
* jsLobeDiffuse
  * Oren-Nayar
  * **TODO:** Subsurface
* jsLobeEmission
  * Intensity
  * Exposure
  * Normalization
  * Contributions:
    * Diffuse
    * Specular
    * Hair
    * Volume
* jsLobeLayering
  * Modes:
    * Physical (Balanced)
    * Artistic (Additive)
* jsLobeScattering
  * Density
  * Anisotropy
* jsLobeSpecular
  * Distributions:
    * GGX
    * Beckmann
    * **TODO:** GTR
  * **TODO:** Metalness
  * **TODO:** Anisotropy
* jsLobeTerminal
* jsLobeTransparent
  * Camera
  * Shadow

Patterns
========

* jsAbs
* jsAdd
* jsAtan
* jsBlackbody
* jsClamp
* jsColorTransform
* jsCompare
* jsComplement
* jsCross
* jsDivide
* jsDot
* jsExp
* jsFractional
* jsIsFinite
* jsIsInfinite
* jsIsNan
* jsLength
* jsLog
* jsMax
* jsMin
* jsMix
* jsModulo
* jsMultiply
* jsNegate
* jsNormalize
* jsPow
* jsRaySwitch
* jsReciprocal
* jsRemap
* jsShaderGlobals
* jsShuffle
* jsSign
* jsSpaceTransform
* jsSpectrum
* jsSqrt
* jsSubtract
* jsWireframe
