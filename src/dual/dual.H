/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2019 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

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
    Foam::dual

Description
    A class representing dual numbers, which are used for forward-mode automatic differentiation.

SourceFiles
    dualI.H
    dual.C

\*---------------------------------------------------------------------------*/

#ifndef dual_H
#define dual_H

#include "scalar.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

class dual;

inline dual operator+(const dual&, const dual&);
inline dual operator-(const dual&, const dual&);
inline dual operator*(const dual&, const dual&);
inline dual operator/(const dual&, const dual&);
Istream& operator>>(Istream&, dual&);
Ostream& operator<<(Ostream&, const dual&);


/*---------------------------------------------------------------------------*\
                           Class dual Declaration
\*---------------------------------------------------------------------------*/

class dual
{
    // private data

        //- Value and derivative parts of the dual number
        scalar value_, derivative_;

public:

    // Constructors

        //- Construct null
        inline dual();

        //- Construct given value and derivative
        inline dual(const scalar value, const scalar derivative);

        //- Construct from Istream
        dual(Istream&);


    // Member Functions

           // Access

               inline scalar value() const;
               inline scalar derivative() const;

           // Edit

               inline scalar& value();
               inline scalar& derivative();


    // Friend operators

        friend dual operator+(const dual&, const dual&);
        friend dual operator-(const dual&, const dual&);
        friend dual operator*(const dual&, const dual&);
        friend dual operator/(const dual&, const dual&);


    // IOstream Operators

        friend Istream& operator>>(Istream&, dual&);
        friend Ostream& operator<<(Ostream&, const dual&);

};


// * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * * //

//- Return a string representation of a dual
word name(const dual&);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dualI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //