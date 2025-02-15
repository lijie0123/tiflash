// Copyright 2023 PingCAP, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <Columns/IColumn.h>
#include <DataStreams/BinaryRowOutputStream.h>
#include <DataTypes/IDataType.h>
#include <IO/WriteBuffer.h>


namespace DB
{

BinaryRowOutputStream::BinaryRowOutputStream(WriteBuffer & ostr_)
    : ostr(ostr_)
{}

void BinaryRowOutputStream::flush()
{
    ostr.next();
}

void BinaryRowOutputStream::writeField(const IColumn & column, const IDataType & type, size_t row_num)
{
    type.serializeBinary(column, row_num, ostr);
}

} // namespace DB
