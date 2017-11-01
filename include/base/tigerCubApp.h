#ifndef TIGER_CUBAPP_H
#define TIGER_CUBAPP_H

#include "MooseApp.h"

class tigerCubApp;

template <>
InputParameters validParams<tigerCubApp>();

class tigerCubApp : public MooseApp
{
public:
  tigerCubApp(InputParameters parameters);
  virtual ~tigerCubApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TIGER_CUBAPP_H */
