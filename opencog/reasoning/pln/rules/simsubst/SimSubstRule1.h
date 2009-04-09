/*
 * Copyright (C) 2002-2007 Novamente LLC
 * Copyright (C) 2008 by Singularity Institute for Artificial Intelligence
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SIMSUBS1RULE_H
#define SIMSUBS1RULE_H

namespace reasoning
{

#if 0
/// Left side stays constant, RHS is substed
class SimSubstRule1 : public GenericRule<InhSubstFormula>
{
public:
	SimSubstRule1(iAtomSpaceWrapper *_destTable)
	: GenericRule<InhSubstFormula>(_destTable, false, "SimSubstRule")
	{
		inputFilter.push_back(meta(new tree<Vertex>(mva((Handle)INHERITANCE_LINK,
			mva((Handle)ATOM),
			mva((Handle)ATOM)))));
		inputFilter.push_back(meta(new tree<Vertex>(mva((Handle)ATOM))));
	}
	setOfMPs o2iMetaExtra(meta outh, bool& overrideInputFilter) const;

	TruthValue** formatTVarray	(const vector<Vertex>& premiseArray, int* newN) const
	{
		TruthValue** tvs = new TruthValue*[1];

		const int N = (int)premiseArray.size();
		assert(N==2);

		tvs[0] = (TruthValue*) &(nm->getTV(v2h(premiseArray[0])));
		tvs[1] = (TruthValue*) &(nm->getTV(v2h(premiseArray[1])));

		return tvs;
	}

	bool validate2				(MPs& args) const { return true; }

	virtual meta i2oType(const vector<Vertex>& h) const;
};

#endif

} // namespace reasoning
#endif // SIMSUBS1RULE_H