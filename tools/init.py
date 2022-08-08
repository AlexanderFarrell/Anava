import sys
import os


def main():
    if len(sys.argv) > 1:
        project_name = sys.argv[1]
        os.mkdir(project_name)
        os.mkdir(project_name + "/Audio")
        os.mkdir(project_name + "/Audio/Music")
        os.mkdir(project_name + "/Audio/Sounds")
        os.mkdir(project_name + "/Config")
        os.mkdir(project_name + "/Mods")
        os.mkdir(project_name + "/Patterns")
        os.mkdir(project_name + "/Visual")
        os.mkdir(project_name + "/Visual/Textures")
        os.mkdir(project_name + "/Visual/Sprites")
        os.mkdir(project_name + "/Visual/Models")
        os.mkdir(project_name + "/Visual/Fonts")
        os.mkdir(project_name + "/Worlds")

        f = open(project_name + "/readme.txt", "w")
        f.write(get_readme_text(project_name))
        f.close()

        f = open(project_name + "/Config/game.cfg", "w")
        f.write(get_config_text())
        f.close()

        print("Initialized project: " + project_name)
    else:
        print("Please enter a name of a project.\n  (Example: python3 init.py my_awesome_game ) \n  "
              "with my_awesome_game being the name of the project ")


def get_readme_text(project_name):
    return f'''## {project_name} ## 

- Creating Mods -

Place mods inside the Mods folder. Mods should come in their own folder.


- Folders -

Audio       Music and sound effects go here
Config      Modify the settings of the game without running.
Mods        Mods for the game go here
Patterns    ?
Visual      Textures, images, fonts and models go here
Worlds      Procedural and handcrafted worlds go here

- Thank you - 

Thank you for playing!

    '''


def get_config_text():
    return '''
; Width and height of the game window
width=1280
height=720

; Fullscreen mode. 
;   1 - Fullscreen
;   0 - Windowed
fullscreen=0
    '''


main()