/*
    EventOS V1.0.1
    Copyright (C) 2014 Edielson Prevato Frigieri. All Rights Reserved.

       This file is part of the EventOS distribution.

    EventOS is free software; you can redistribute it and/or modify it under
    the terms of the MIT License (MIT).
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

 */

/**
 * @file eventos_test_runner.c
 * @brief The function to be called to run all the tests.
 */

/* Test runner interface includes. */
#include "eventos_test_runner.h"

/* EventOS includes. */
#include "EventOS.h"
#include "event.h"

/* Unity framework includes. */
#include "unity_fixture.h"
#include "unity_internals.h"

/* Application version info. */
#include "eventos_application_version.h"

const AppVersion32_t xAppFirmwareVersion =
{
    .u.x.ucMajor = APP_VERSION_MAJOR,
    .u.x.ucMinor = APP_VERSION_MINOR,
    .u.x.usBuild = APP_VERSION_BUILD,
};

char cBuffer[ testrunnerBUFFER_SIZE ];

/*-----------------------------------------------------------*/

/* This function will be generated by the test automation framework,
 * do not change the signature of it. You could, however, add or remove
 * RUN_TEST_GROUP statements.
 */
static void RunTests( void )
{
    /* Tests can be disabled in eventos_test_runner_config.h */

    #if ( testrunnerFULL_EVENT_ENABLED == 1 )
        RUN_TEST_GROUP( Full_EVENTOS_EVENT );
    #endif


}
/*-----------------------------------------------------------*/

void TEST_RUNNER_RunTests( void )
{
    /* Initialize unity. */
    UnityFixture.Verbose = 1;
    UnityFixture.GroupFilter = 0;
    UnityFixture.NameFilter = 0;
    UnityFixture.RepeatCount = 1;

    UNITY_BEGIN();
    
	RunTests();

    /* Currently disabled. Will be enabled after cleanup. */
    UNITY_END();
}
/*-----------------------------------------------------------*/
