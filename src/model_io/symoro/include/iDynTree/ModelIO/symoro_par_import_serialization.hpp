/*
 * Copyright (C) 2013 Fondazione Istituto Italiano di Tecnologia
 *
 * Licensed under either the GNU Lesser General Public License v3.0 :
 * https://www.gnu.org/licenses/lgpl-3.0.html
 * or the GNU Lesser General Public License v2.1 :
 * https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
 * at your option.
 */

/* Author:  Silvio Traversaro */

#ifndef SYMORO_PAR_IMPORT_SERIALIZATION_H
#define SYMORO_PAR_IMPORT_SERIALIZATION_H

#include <string>

#include "symoro_par_import.hpp"
#include "symoro_par_model.hpp"

namespace KDL {
    class Tree;

    namespace CoDyCo {
        class TreeSerialization;
    }
}

namespace iDynTree
{

/** Constructs a KDL::CoDyCo tree serialization from a .par file, given the file name
 *  The .par file is produced by the Symoro+ software
 * \param file The filename from where to read the .par file
 * \param serialization The resulting KDL::CoDyCo TreeSerialization
 * \param consider_root_link_inertia optional (default true) if true parse the first link
 *                  of the robot model as a real link, and introduces a dummy link connected to it
 *                 with a fixed joint to overcome the the fact that KDL does not support inertia in the first link
 * returns true on success, false on failure
 */
bool treeSerializationFromSymoroParFile(const std::string& parfile_name, KDL::CoDyCo::TreeSerialization& serialization,  const bool consider_root_link_inertia=true);

/** Constructs a KDL tree from a string of the contents of the par file
 * \param xml A string containting the Symoro+ par description of the robot
 * \param serialization The resulting KDL::CoDyCo TreeSerialization
 * \param consider_root_link_inertia optional (default true) if true parse the first link
 *                  of the robot model as a real link, and introduces a dummy link connected to it
 *                 with a fixed joint to overcome the the fact that KDL does not support inertia in the first link
 * returns true on success, false on failure
 */
bool treeSerializationFromSymoroParString(const std::string& parfile_content, KDL::CoDyCo::TreeSerialization& serialization, const bool consider_root_link_inertia=true);

/** Constructs a KDL tree from a structure representation of the contents of the par file
 * \param par_model A symoro_par_model object containing the Symoro+ par description of the robot
 * \param serialization The resulting KDL::CoDyCo TreeSerialization
 * \param consider_root_link_inertia optional (default true) if true parse the first link
 *                  of the robot model as a real link, and introduces a dummy link connected to it
 *                 with a fixed joint to overcome the the fact that KDL does not support inertia in the first link
 * returns true on success, false on failure
 */
bool treeSerializationFromParModel(const symoro_par_model & par_model, KDL::CoDyCo::TreeSerialization& serialization, const bool consider_root_link_inertia=true);

}

#endif
