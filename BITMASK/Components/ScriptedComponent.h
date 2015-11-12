#pragma once
#include "Component.h"
#include <functional>
#include <memory>

namespace chaiscript
{
	class ChaiScript;
	class Module;
}

namespace bit
{
	class ScriptedComponent : public Component
	{
		private:
			chaiscript::ChaiScript* scriptEngine;
			std::shared_ptr<chaiscript::Module> internalModule;

			// Is this ready to be run?
			bool loaded = false;

			// Path to the source file/resource
			std::string modulePath;

		public:
			explicit ScriptedComponent(const std::string& modulePath);
			~ScriptedComponent() override;

			void added() override;
			void removed() override;

			// Init the script component
			void init(chaiscript::ChaiScript* scriptEngine);

			// Load a function from the module 
			std::function<void()> getScriptFunction(std::string functionName) const;
	};
}