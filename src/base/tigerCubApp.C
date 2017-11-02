#include "tigerCubApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"
#include "HeatConduction.h"
#include "HfAlMaterial.h"
#include "HfAlBulkMaterial.h"

template <>
InputParameters
validParams<tigerCubApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

tigerCubApp::tigerCubApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  tigerCubApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  tigerCubApp::associateSyntax(_syntax, _action_factory);
}

tigerCubApp::~tigerCubApp() {}

// External entry point for dynamic application loading
extern "C" void
tigerCubApp__registerApps()
{
  tigerCubApp::registerApps();
}
void
tigerCubApp::registerApps()
{
  registerApp(tigerCubApp);
}

void
tigerCubApp::registerObjectDepends(Factory & /*factory*/)
{
}

// External entry point for dynamic object registration
extern "C" void
tigerCubApp__registerObjects(Factory & factory)
{
  tigerCubApp::registerObjects(factory);
}
void
tigerCubApp::registerObjects(Factory & /*factory*/)
{
}

void
tigerCubApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
tigerCubApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  tigerCubApp::associateSyntax(syntax, action_factory);
}
void
tigerCubApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
