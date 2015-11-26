/*
 * Copyright (C) 2015 Fondazione Istituto Italiano di Tecnologia
 * Authors: Silvio Traversaro
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#ifndef IDYNTREE_SPATIAL_MOTION_RAW_H
#define IDYNTREE_SPATIAL_MOTION_RAW_H

#include <iDynTree/Core/VectorFixSize.h>
#include <iDynTree/Core/LinearMotionVector3.h>
#include <iDynTree/Core/AngularMotionVector3.h>
#include <iDynTree/Core/SpatialVector.h>
#include <iDynTree/Core/PrivateMotionForceVertorAssociations.h>

namespace iDynTree
{
    class SpatialForceVector;
    class Transform;
    class Dummy {};

    /**
     * Class providing the raw coordinates for any motion spatial vector
     * (i.e. vector form of an element of se(3)).
     *
     * \ingroup iDynTreeCore
     *
     * A motion spatial vector can be used to to describe a twist, twist acceleration
     * or their derivatives.
     *
     * A generic motion spatial vector can also be used to store the logarithm of
     * an iDynTree::Transform (i.e. an element of SE(3)).
     *
     * This is just a basic vector, used to implement the adjoint transformations in
     * a general way. The relative adjoint transformation is contained in
     * TransformRaw::apply(SpatialMotionRaw),
     * for consistency with the iDynTree::PositionRaw class.
     *
     * \note in iDynTree, the spatial vector follows this serialization: the first three elements are
     *       the linear part and the second three elements are the angular part.
     */

    class SpatialMotionVector: public SpatialVector<SpatialMotionVector>
    {
    public:
        /**
         * We use traits here to have the associations SpatialVector <=> Linear/Angular 3D vectors types
         * defined in a single place.
         */
        typedef SpatialMotionForceVectorT_traits<SpatialMotionVector>::LinearVector3Type LinearVector3T;
        typedef SpatialMotionForceVectorT_traits<SpatialMotionVector>::AngularVector3Type AngularVector3T;

        /**
         * constructors
         */
        inline SpatialMotionVector() {};
        SpatialMotionVector(const LinearVector3T & _linearVec3, const AngularVector3T & _angularVec3);
        SpatialMotionVector(const SpatialMotionVector & other);
        SpatialMotionVector(const SpatialVector<SpatialMotionVector> & other);

        /**
         * Multiplication for a scalar.
         * Mainly used if SpatialMotionVector is used to represent a motion subspace.
         */
        SpatialMotionVector operator*(const double scalar) const;

        /**
         * Cross product
         */
        SpatialMotionVector cross(const SpatialMotionVector& other) const;
        SpatialForceVector cross(const SpatialForceVector& other) const;

        /**
         * Exp mapping between a  generic element of se(3) (iDynTree::SpatialMotionVector)
         * to the corresponding element of SE(3) (iDynTree::Transform).
         */
        Transform exp() const;
    };

}

#endif /* IDYNTREE_SPATIAL_MOTION_RAW_H */