/**
 * Copyright 2020 curoky(cccuroky@gmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <catch2/catch.hpp>

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtCore/QtCore>

#include "diff_match_patch.h"

TEST_CASE("[Google-diff]: basic usage") {
  diff_match_patch dmp;

  QString str1 = QString("First string in diff");
  QString str2 = QString("Second string in diff");

  QString strPatch = dmp.patch_toText(dmp.patch_make(str1, str2));
  QList<Patch> patches = dmp.patch_fromText(strPatch);

  QPair<QString, QVector<bool>> out = dmp.patch_apply(patches, str1);

  QString strResult = out.first;
  // here, strResult will equal str2 above.
  // REQUIRE(strResult == str2);
}
