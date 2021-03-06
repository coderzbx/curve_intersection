#pragma once

#include "curve_intersection/Serializer/FormattedCurveSerializer.hxx"
#include "curve_intersection/Curves/ICurve.hxx"
#include <memory>
#include <string>
#include <vector>
#include <map>

namespace CurveIntersection {

class CurveExchanger {
public:
	CurveExchanger();
	template<typename FormattedSerializer>
	void RegisterSerializer();

	std::unique_ptr<ICurve> Read(std::istream& theStream, FormattedCurveSerializer::Format theFormat);
	void Write(std::ostream& theStream, const ICurve& aCurve, FormattedCurveSerializer::Format theFormat);

	std::vector<std::shared_ptr<ICurve>> ReadCurves(std::string theFileName);
	void WriteCurves(const std::vector<std::shared_ptr<ICurve>>& theCurves, std::string theFileName);

private:

	std::map<std::string, std::shared_ptr<FormattedCurveSerializer> > mySerializers;


};
}



