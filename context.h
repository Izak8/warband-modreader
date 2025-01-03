#ifndef CONTEXT_H
#define CONTEXT_H


/* Gameplay-related files */
typedef struct mbmr_strings {
}mbmr_strings;

typedef struct mbmr_scripts {
}mbmr_scripts;

typedef struct mbmr_simple_triggers {
}mbmr_simple_triggers;

typedef struct mbmr_triggers {
}mbmr_triggers;

typedef struct mbmr_factions {
}mbmr_factions;

/* Agent-related files */

typedef struct mbmr_skills {
}mbmr_skills;

typedef struct mbmr_skins {
}mbmr_skins;

typedef struct mbmr_troops {
}mbmr_troops;

typedef struct mbmr_items {
}mbmr_items;

typedef struct mbmr_animations {
}mbmr_animations;

/* Scene-related files */

typedef struct mbmr_scene_props {
}mbmr_scene_props;

typedef struct mbmr_scenes {
}mbmr_scenes;

typedef struct mbmr_mission_templates {
}mbmr_mission_templates;

/* Map-related files */

typedef struct mbmr_map_icons {
}mbmr_map_icons;

typedef struct mbmr_parties {
}mbmr_parties;

typedef struct mbmr_party_templates {
}mbmr_party_templates;


/* Mount & Blade Module Reader Context */
/* Context struct holds all information about a given module */
typedef struct mbmr_context {

    /* Path to a given compiled module system */
    char* modpath;

    /* TODO */
    mbmr_strings strings;
    mbmr_scripts scripts;
    mbmr_simple_triggers simple_triggers;
    mbmr_triggers triggers;
    mbmr_factions factions;

    mbmr_skills skills;
    mbmr_skins skins;
    mbmr_troops troops;
    mbmr_items items;
    mbmr_animations animations;

    mbmr_scene_props scene_props;
    mbmr_scenes scenes;
    mbmr_mission_templates mission_templates;
    
    mbmr_map_icons map_icons;
    mbmr_parties parties;
    mbmr_party_templates party_templates;

}mbmr_context;

#endif