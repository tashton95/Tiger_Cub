#ifndef TIGER_CUBTESTAPP_H
#define TIGER_CUBTESTAPP_H

#include "MooseApp.h"

class tigerCubTestApp;

template <>
InputParameters validParams<tigerCubTestApp>();

class tigerCubTestApp : public MooseApp
{
public:
  tigerCubTestApp(InputParameters parameters);
  virtual ~tigerCubTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TIGER_CUBTESTAPP_H */
