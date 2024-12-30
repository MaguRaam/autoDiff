/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "dual.H"
#include "IOstreams.H"

#include <sstream>

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::dual::dual(Istream& is)
{
    is >> *this;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::word Foam::name(const dual& d)
{
    std::ostringstream buf;
    buf << '(' << d.value() << ',' << d.derivative() << ')';
    return buf.str();
}


// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

Foam::Istream& Foam::operator>>(Istream& is, dual& d)
{
    // Read beginning of dual
    is.readBegin("dual");

    is  >> d.value_ >> d.derivative_;

    // Read end of dual
    is.readEnd("dual");

    // Check state of Istream
    is.check("operator>>(Istream&, dual&)");

    return is;
}


Foam::Ostream& Foam::operator<<(Ostream& os, const dual& d)
{
    os  << token::BEGIN_LIST
        << d.value_ << token::SPACE << d.derivative_
        << token::END_LIST;

    return os;
}


// ************************************************************************* //