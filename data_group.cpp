#include "data_group.h"

data_group::data_group()
{
    pcs_system_status   = PCS_INITIAL;
    pcs_system_warning  = PCS_NORMAL;
    dc_grid_conversion_status = DC_GRID_CONV_NOT_RUNNING;
    dc_grid_conversion_warning_status = DC_GRID_CONV_NORMAL;
    ac_inv_conversion_status = INVERTER_IDLE;
    ac_inv_warning_status = INVERTER_NORMAL;
    pv_converter_status = PV_CONVERTER_NOT_RUNNING;
    pv_converter_warning = PV_CONVERTER_NORMAL;
    battery_converter_status = BATTERY_CONVERTER_NOT_RUNNING;
    battery_converter_warning = BATTERY_CONVERTER_NORMAL;
    bmc_pcs_status = BMC_PCS_STOP;
    bmc_command_to_pcs = PCS_PROCEED_STOP;
    precharge_relay_status = PRECHARGE_RELAY_OPEN;
    main_relay_status = MAIN_RELAY_OPEN;
    for(uint8_t i=0; i< PACKET_LENGTH; i++)
    {
        buffer[i] = 0x00;
    }
}
