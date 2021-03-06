/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2012 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::combustionModels::eddyDissipationLimitModel

Description
    Simple infinitely fast chemistry combustion model based on the principle
    mixed is burnt. Additional parameter C is used to distribute the heat
    release rate.in time

SourceFiles
    eddyDissipationLimitModel.C

\*---------------------------------------------------------------------------*/

#ifndef eddyDissipationLimitModel_H
#define eddyDissipationLimitModel_H

#include "singleStepCombustion.H"

#include "LESModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace combustionModels
{

/*---------------------------------------------------------------------------*\
                  Class eddyDissipationLimitModel Declaration
\*---------------------------------------------------------------------------*/

template<class CombThermoType, class ThermoType>
class eddyDissipationLimitModel
:
    public singleStepCombustion<CombThermoType, ThermoType>
{
    // Private data

        //- Model constant
        scalar C_;

        scalar Cd_;

        scalar Cstiff_;

    // Private Member Functions

        //- Return the reciprocal of the turbulent mixing time scale
        tmp<volScalarField> rtTurb() const;

        //- Return the reciprocal of the diffusion time scale
        tmp<volScalarField> rtDiff() const;

        //- Disallow copy construct
        eddyDissipationLimitModel(const eddyDissipationLimitModel&);

        //- Disallow default bitwise assignment
        void operator=(const eddyDissipationLimitModel&);


public:

    //- Runtime type information
    TypeName("eddyDissipationLimitModel");


    // Constructors

        //- Construct from components
        eddyDissipationLimitModel
        (
            const word& modelType,
            const fvMesh& mesh,
            const word& phaseName
        );


    //- Destructor
    virtual ~eddyDissipationLimitModel();


    // Member Functions

        // Evolution

            //- Correct combustion rate
            virtual void correct();


        // IO

            //- Update properties
            virtual bool read();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace combustionModels
} // End namespace Foam


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include "eddyDissipationLimitModel.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
