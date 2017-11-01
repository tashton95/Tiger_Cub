#include "tigerCubTestApp.h"
#include "tigerCubApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<tigerCubTestApp>()
{
  InputParameters params = validParams<tigerCubApp>();
  return params;
}

tigerCubTestApp::tigerCubTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  tigerCubApp::registerObjectDepends(_factory);
  tigerCubApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  tigerCubApp::associateSyntaxDepends(_syntax, _action_factory);
  tigerCubApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    tigerCubTestApp::registerObjects(_factory);
    tigerCubTestApp::associateSyntax(_syntax, _action_factory);
  }
}

tigerCubTestApp::~tigerCubTestApp() {}

// External entry point for dynamic application loading
extern "C" void
tigerCubTestApp__registerApps()
{
  tigerCubTestApp::registerApps();
}
void
tigerCubTestApp::registerApps()
{
  registerApp(tigerCubApp);
  registerApp(tigerCubTestApp);
}

// External entry point for dynamic object registration
extern "C" void
tigerCubTestApp__registerObjects(Factory & factory)
{
  tigerCubTestApp::registerObjects(factory);
}
void
tigerCubTestApp::registerObjects(Factory & /*factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
tigerCubTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  tigerCubTestApp::associateSyntax(syntax, action_factory);
}
void
tigerCubTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
