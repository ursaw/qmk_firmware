"""QMK latex macros like in https://getreuer.info/posts/keyboards/macros/index.html


register_mods(MOD_BIT(KC_RALT));
register_code(KC_7);
unregister_code(KC_7);
unregister_mods(MOD_BIT(KC_RALT));



"""
from dataclasses import dataclass


@dataclass
class DEXmacro:
    key: str = ""
    """new keycode. e.g. DEX_1"""

    dw_cd: str = ""
    dw_mod: str = ""

    up_cd: str = ""
    up_mod: str = ""


    
    def get_key_code(self):
        """Name of the macro."""
        return f"DEX_{self.key.upper()}"

#   case TEX_D:
#            if (record->event.pressed) {
#                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Delta ");add_mods(MOD_MASK_SHIFT);}
#                else                                       { SEND_STRING("\\delta ");}
#            }
#      return true;

    def qmk_code(self):
        """C++ code generation."""

        def reg_unreg(code, mod, pre=' '*20):
            str = ''
            if mod:
                str = str + f'{pre}register_mods({mod});'+'\n'
            str = str + f'{pre}register_code({code});'+'\n'
            str = str + f'{pre}unregister_code({code});'+'\n'
            if mod:
                str = str + f'{pre}unregister_mods({mod});'+'\n'
            return str
        


        str = f'''    case {self.get_key_code()}:
            if (record->event.pressed) {{
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) {{
                    unregister_mods(MOD_BIT(MOD_MASK_SHIFT));\n'''
        str = str + reg_unreg(self.up_cd, self.up_mod)
        str = str + "                } else {\n"
        str = str + reg_unreg(self.dw_cd, self.dw_mod)
                   

        str += '''           }
      return true;
'''
        print(str)
        return

pass

dex_list = list()
dex_list.append(DEXmacro('2', 'KC_2', '', 'KC_Q', 'MOD_BIT(KC_RALT)') )

for e in dex_list:
    e.qmk_code()


# create custum keycodes
key_list = [x.get_key_code() for x in dex_list]
key_list[0] = f'{key_list[0]} = SAFE_RANGE'
print('enum custom_keycodes {')
for x in key_list:
    print(f"  {x},")
print("};")
pass
