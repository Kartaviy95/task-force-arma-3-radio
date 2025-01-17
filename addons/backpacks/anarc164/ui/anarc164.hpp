/* #Lirixu
$[
    1.063,
    ["anarc164",[["0","0","1","1"],"0.0025","0.004","GUI_GRID"],0,1,1],
    [1200,"background",[1,"task_force_radio\anarc164\anarc164.paa",["0.0413536 * safezoneW + safezoneX","0.0434751 * safezoneH + safezoneY","0.431062 * safezoneW","0.7513 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"channel_edit",[1,"CH:3",["0.288078 * safezoneW + safezoneX","0.2382 * safezoneH + safezoneY","0.0324844 * safezoneW","0.0374 * safezoneH"],[1,0.5,0,1],[1,0.5,0,1],[0,1,0,1],"Current channel","-1"],[]],
    [1401,"edit",[1,"88.8",["0.201969 * safezoneW + safezoneX","0.3515 * safezoneH + safezoneY","0.0995156 * safezoneW","0.0352 * safezoneH"],[1,0.5,0,1],[1,0.5,0,1],[0,0,0,1],"Current frequency","-1"],[]],
    [1600,"enter",[1,"",["0.233422 * safezoneW + safezoneX","0.4373 * safezoneH + safezoneY","0.037125 * safezoneW","0.0693 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Set frequency","-1"],[]],
    [1601,"clear",[1,"",["0.168453 * safezoneW + safezoneX","0.4362 * safezoneH + safezoneY","0.0376406 * safezoneW","0.0715 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Clear frequency","-1"],[]],
    [1602,"prev_channel",[1,"",["0.297875 * safezoneW + safezoneX","0.4384 * safezoneH + safezoneY","0.0360937 * safezoneW","0.0671 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Previous channel","-1"],[]],
    [1604,"increase_volume",[1,"",["0.239094 * safezoneW + safezoneX","0.5451 * safezoneH + safezoneY","0.02475 * safezoneW","0.0462 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Change volume","-1"],[]],
    [1605,"stereo",[1,"",["0.115344 * safezoneW + safezoneX","0.566 * safezoneH + safezoneY","0.0665527 * safezoneW","0.110006 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1606,"additional",[1,"",["0.103008 * safezoneW + safezoneX","0.434185 * safezoneH + safezoneY","0.0374025 * safezoneW","0.0700156 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1607,"speakers",[1,"",["0.27633 * safezoneW + safezoneX","0.630886 * safezoneH + safezoneY","0.0293761 * safezoneW","0.0406957 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

class anarc164_radio_dialog {
    idd = IDD_ANARC164_RADIO_DIALOG;
    movingEnable = 1;
    controlsBackground[] = { };
    onUnload = "['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'anarc164_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
    objects[] = {};
    controls[]= {
        QUOTE(background),
        QUOTE(enter),
        QUOTE(channel_edit),
        QUOTE(edit),
        QUOTE(clear),
        QUOTE(prev_channel),
        QUOTE(increase_volume),
        QUOTE(stereo),
        QUOTE(additional),
        QUOTE(speakers)
    };

    class background: RscBackPicture {
        idc = IDC_ANARC164_BACKGROUND;
        text = QPATHTOF(anarc164\ui\anarc164.paa);
        x = QUOTE(0.0413536 * safezoneW + safezoneX);
        y = QUOTE(0.0434751 * safezoneH + safezoneY);
        w = QUOTE(0.431062 * safezoneW);
        h = QUOTE(0.7513 * safezoneH);
        moving = 1;
    };
    class channel_edit: RscEditLCD {
        idc = IDC_ANARC164_CHANNEL_EDIT;
        x = QUOTE(0.288078 * safezoneW + safezoneX);
        y = QUOTE(0.2382 * safezoneH + safezoneY);
        w = QUOTE(0.0324844 * safezoneW);
        h = QUOTE(0.0374 * safezoneH);
        colorText[] = {1,0.5,0,1};
        colorBackground[] = {0,0,0,0};
        colorActive[] = {0,1,0,1};
        font = "TFAR_font_segments";
        shadow = 1;
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
        tooltip = ECSTRING(core,current_channel);
        canModify = 0;
    };
    class edit: RscEditLCD {
        idc = IDC_ANARC164_EDIT;
        x = QUOTE(0.201969 * safezoneW + safezoneX);
        y = QUOTE(0.3515 * safezoneH + safezoneY);
        w = QUOTE(0.0995156 * safezoneW);
        h = QUOTE(0.0352 * safezoneH);
        colorText[] = {1,0.5,0,1};
        colorBackground[] = {0,0,0,0};
        colorActive[] = {0,0,0,1};
        font = "TFAR_font_segments";
        shadow = 1;
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 23) * 1.2)";
        tooltip = ECSTRING(core,current_freq);
        canModify = 1;
        onKeyUp = QUOTE( \
            if (_this select 1 in [ARR_2(28,156)]) then { \
                [((ctrlParent (_this select 0))) displayCtrl IDC_ANARC164_EDIT] call TFAR_backpacks_fnc_onButtonClick_Enter; \
            }; \
        );
    };
    class enter: HiddenRotator {
        idc = IDC_ANARC164_ENTER;
        x = QUOTE(0.233422 * safezoneW + safezoneX);
        y = QUOTE(0.4373 * safezoneH + safezoneY);
        w = QUOTE(0.037125 * safezoneW);
        h = QUOTE(0.0693 * safezoneH);
        tooltip = ECSTRING(core,set_frequency);
        onButtonClick = QUOTE( \
            playSound 'TFAR_rotatorPush'; \
            [((ctrlParent (_this select 0))) displayCtrl IDC_ANARC164_EDIT] call TFAR_backpacks_fnc_onButtonClick_Enter; \
        );
        action = "";
    };
    class clear: HiddenRotator {
        idc = IDC_ANARC164_CLEAR;
        x = QUOTE(0.168453 * safezoneW + safezoneX);
        y = QUOTE(0.4362 * safezoneH + safezoneY);
        w = QUOTE(0.0376406 * safezoneW);
        h = QUOTE(0.0715 * safezoneH);
        tooltip = ECSTRING(core,clear_frequency);
        action = QUOTE( \
            playSound 'TFAR_rotatorPush'; \
            ctrlSetText [ARR_2(IDC_ANARC164_EDIT,'')]; \
            ctrlSetFocus ((findDisplay IDD_ANARC164_RADIO_DIALOG) displayCtrl IDC_ANARC164_EDIT); \
        );
    };
    class prev_channel: HiddenRotator {
        idc = IDC_ANARC164_PREV_CHANNEL;
        x = QUOTE(0.297875 * safezoneW + safezoneX);
        y = QUOTE(0.4384 * safezoneH + safezoneY);
        w = QUOTE(0.0360937 * safezoneW);
        h = QUOTE(0.0671 * safezoneH);
        tooltip = ECSTRING(core,rotator_channel);
        onMouseButtonDown = "[_this select 1, true, '%1'] call TFAR_fnc_setChannelViaDialog;";
    };
    class increase_volume: HiddenRotator {
        idc = IDC_ANARC164_INCREASE_VOLUME;
        x = QUOTE(0.239094 * safezoneW + safezoneX);
        y = QUOTE(0.5451 * safezoneH + safezoneY);
        w = QUOTE(0.02475 * safezoneW);
        h = QUOTE(0.0462 * safezoneH);
        tooltip = ECSTRING(core,rotator_volume);
        onMouseButtonDown = "[_this select 1, true] call TFAR_fnc_setVolumeViaDialog;";
    };
    class stereo: HiddenRotator {
        idc = IDC_ANARC164_STEREO;
        x = QUOTE(0.115344 * safezoneW + safezoneX);
        y = QUOTE(0.566 * safezoneH + safezoneY);
        w = QUOTE(0.0665527 * safezoneW);
        h = QUOTE(0.110006 * safezoneH);
        action = QUOTE( \
            playSound 'TFAR_rotatorPush'; \
            [ARR_2(TF_lr_dialog_radio, ((TF_lr_dialog_radio call TFAR_fnc_getCurrentLrStereo) + 1) mod TFAR_MAX_STEREO)] call TFAR_fnc_setLrStereo; \
            [TF_lr_dialog_radio] call TFAR_fnc_showRadioVolume; \
        );
        tooltip = ECSTRING(core,stereo_settings);
    };
    class additional: HiddenRotator {
        idc = IDC_ANARC164_ADDITIONAL;
        x = QUOTE(0.103008 * safezoneW + safezoneX);
        y = QUOTE(0.434185 * safezoneH + safezoneY);
        w = QUOTE(0.0374025 * safezoneW);
        h = QUOTE(0.0700156 * safezoneH);
        tooltip = ECSTRING(core,set_additional);
        action ="playSound 'TFAR_rotatorPush';[TF_lr_dialog_radio,TF_lr_dialog_radio call TFAR_fnc_getLrChannel] call TFAR_fnc_setAdditionalLrChannel;call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
    };
    class speakers: HiddenFlip {
        idc = IDC_ANARC164_SPEAKERS;
        x = QUOTE(0.27633 * safezoneW + safezoneX);
        y = QUOTE(0.630886 * safezoneH + safezoneY);
        w = QUOTE(0.0293761 * safezoneW);
        h = QUOTE(0.0406957 * safezoneH);
        tooltip = ECSTRING(core,speakers_settings_true);
        action = "TF_lr_dialog_radio call TFAR_fnc_setLrSpeakers;[TF_lr_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
    };
};
