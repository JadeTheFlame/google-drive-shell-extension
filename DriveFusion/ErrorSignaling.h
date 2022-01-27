/*
Copyright 2015 Google Inc

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#define LSTR_(value) L#value

#define LSTR(value) LSTR_(value)

#define CHECK_ARG(condition) \
        do \
        { \
            if (!(condition)) \
            { \
                hr = E_INVALIDARG; \
                Log::WriteOutput( \
                        LogType::Error, LSTR(__FILE__) L":" LSTR(__LINE__) \
                        L" - Argument failed condition " L#condition); \
                return hr; \
            } \
        } while (false)

#define CHECK_HR(hresult) \
        do \
        { \
            hr = hresult; \
            if (!SUCCEEDED(hr)) \
            { \
                Log::WriteOutput( \
                        LogType::Error, LSTR(__FILE__) L":" LSTR(__LINE__) \
                        L" - " L#hresult L" failed, hr = %x", hr); \
                return hr; \
            } \
        } while (false)

#define CHECK_TRUE(condition, hrFail) \
        do \
        { \
            if (!(condition)) \
            { \
                hr = hrFail; \
                Log::WriteOutput( \
                        LogType::Error, LSTR(__FILE__) L":" LSTR(__LINE__) \
                        L" - " L#condition L" failed, " L#hrFail L" = %x", hr); \
                return hr; \
            } \
        } while (false)
