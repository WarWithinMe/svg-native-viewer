/*
Copyright 2019 Adobe. All rights reserved.
This file is licensed to you under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License. You may obtain a copy
of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under
the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS
OF ANY KIND, either express or implied. See the License for the specific language
governing permissions and limitations under the License.
*/

#pragma once

#include "SVGDocumentImpl.h"
#include <functional>
#include <map>
#include <string>

namespace SVGNative
{
namespace SVGStringParser
{
std::unique_ptr<Transform> ParseTransform(const std::string& transformString, std::function<std::unique_ptr<Transform>()> createTransform);
bool ParseNumber(const std::string& numberString, float& number);
bool ParseListOfNumbers(const std::string& numberListString, std::vector<float>& numberList, bool isAllOptinoal = true);
bool ParseListOfLengthOrPercentage(
    const std::string& lengthOrPercentageListString, float relDimensionLength, std::vector<float>& numberList, bool isAllOptinoal = true);
bool ParseListOfStrings(const std::string& stringListString, std::vector<std::string>& stringList);
bool ParseLengthOrPercentage(const std::string& lengthString, float relDimensionLength, float& absLengthInUnits, bool useQuirks = false);
void ParsePathString(const std::string& pathString, Path& p);
SVGDocumentImpl::Result ParseColor(const std::string& colorString, ColorImpl& paint, bool supportsCurrentColor = true);
SVGDocumentImpl::Result ParsePaint(const std::string& colorString, const std::map<std::string, GradientImpl>& gradientMap,
    std::vector<std::int32_t>& viewBox, PaintImpl& paint);

} // namespace SVGStringParser

} // namespace SVGNative
