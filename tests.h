#pragma once
#include "UserInterface.h"
#include <assert.h>

//Entity.h
void testEntityConstructors();
void testEntitySetters();
void testEntityGettters();
void testEntityOperators();

//Repository.h
void testRepositoryConstructors();
void testRepositorySetters();
void testRepositoryGetters();
void testRepositoryAddItem();
void testRepositoryOperators();

//Service.h
void testServiceConstructors();
void testServiceSetters();
void testServiceGetters();
void testServiceOperators();
void testServiceAddFunction();
void testServiceDelFunction();
void testServiceFindFunction();
void testServiceImprumutFunction();

//UserInterface.h
void testUserInterfaceConstructors();
void testUserInterfaceSetters();
void testUserInterfaceGettters();

void TestAll();
