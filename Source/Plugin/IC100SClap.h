// IC100SClap.h
// The three entry functions clap-wrapper links into every format.

#pragma once

bool tbic_entry_init (const char* pluginPath);
void tbic_entry_deinit();
const void* tbic_entry_get_factory (const char* factoryId);
