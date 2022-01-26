#ifndef DATA_GROUP_H
#define DATA_GROUP_H

#include <QObject>

class data_group
{
public:
    data_group();



    uint8_t pcs_system;
    uint8_t dcgrid_system;
    uint8_t inv_system;
    uint8_t pvconv_system;
    uint8_t batconv_system;

    /* pcs sensors */
    float 	 vDC_grid;
    float 	 vAC_inv;
    float 	 vPv_conv;
    float 	 vBat_conv;
    float 	 iDC_grid;
    float 	 iAC_inv;
    float 	 iPv_conv;
    float 	 iBat_conv;
    int16_t  pDC_grid;
    uint16_t pAC_inv;
    uint16_t pPv_conv;
    int16_t  pBat_conv;
    float 	 temp_sensor;
    float 	 frequency;

    /* bmc status */
    uint8_t  bmc_system;

    /* battery information */
    uint8_t  soC;
    uint16_t vBat_genix;
    float 	 iBat_genix;
    uint8_t  temp_genix;

private:
    /* pcs converter system */
    typedef enum
    {
        PCS_INITIAL,
        PCS_STANDBY,
        PCS_RUNNING
    } pcs_system_status_t;

    typedef enum
    {
        PCS_NORMAL,
        PCS_OVER_TEMPERATURE,
        BATTERY_OVER_CHARGE,
        BATTERY_CHARGE_SUPPRESSION,
        BATTERY_DISCHARGE_SUPPRESSION,
        BATTERY_CHARGE_PRIORITY,
        BATTERY_STOP
    } pcs_system_warning_status_t;

    typedef enum
    {

        DC_GRID_CONV_NOT_RUNNING,
        DC_GRID_CONV_CHARGING,
        DC_GRID_CONV_DISCHARGING
    } dc_grid_conversion_status_t;

    typedef enum
    {
        DC_GRID_CONV_NORMAL,
        GRID_CONVERTER_OVERVOLTAGE,
        GRID_CONVERTER_OVERCURRENT
    } dc_grid_conversion_warning_status_t;

    typedef enum
    {
        INVERTER_NOT_RUNNING,
        INVERTER_IDLE,
        INVERTER_RUNNING
    } ac_inv_system_status_t;

    typedef enum
    {
        INVERTER_NORMAL,
        INVERTER_MCU_DC_LINK_OVERVOLTAGE,
        INVERTER_OVER_TEMPERATURE,
        INVERTER_OVER_VOLTAGE,
        INVERTER_UNDER_VOLTAGE,
        INVERTER_OVERLOAD
    } ac_inv_warning_status_t;

    typedef enum
    {
        PV_CONVERTER_NOT_RUNNING,
        PV_CONVERTER_RUNNING
    } pv_converter_status_t;

    typedef enum {
        PV_CONVERTER_NORMAL,
        PV_CONVERTER_OVER_VOLTAGE,
        PV_CONVERTER_OVER_CURRENT
    } pv_converter_warning_status_t;

    typedef enum{
        BATTERY_CONVERTER_NOT_RUNNING,
        BATTERY_CONVERTER_RUNNING
    } battery_converter_status_t;

    typedef enum {
        BATTERY_CONVERTER_NORMAL,
        BATTERY_OVER_VOLTAGE,
        BATTERY_OVER_CURRENT,
        BATTERY_MCU_DC_LINK_OVERVOLTAGE,
        BATTERY_CONVERTER_OVERCURRENT
    } battery_converter_warning_status_t;

    typedef enum {
        BMC_PCS_STOP,
        BMC_PCS_PRECHARGE,
        BMC_PCS_RUNNING,
        BMC_PCS_FAULT
    } bmc_pcs_status_t;

    typedef enum {
        PCS_PROCEED_STOP,
        PCS_PROCEED_RUN
    } bmc_command_to_pcs_t;

    typedef enum {
        PRECHARGE_RELAY_OPEN,
        PRECHARGE_RELAY_CLOSE
    } precharge_relay_status_t;

    typedef enum {
        MAIN_RELAY_OPEN,
        MAIN_RELAY_CLOSE
    } main_relay_status_t;

    pcs_system_status_t                 pcs_system_status;
    pcs_system_warning_status_t         pcs_system_warning;
    dc_grid_conversion_status_t         dc_grid_conversion_status;
    dc_grid_conversion_warning_status_t dc_grid_conversion_warning_status;
    ac_inv_system_status_t              ac_inv_conversion_status;
    ac_inv_warning_status_t             ac_inv_warning_status;
    pv_converter_status_t               pv_converter_status;
    pv_converter_warning_status_t       pv_converter_warning;
    battery_converter_status_t          battery_converter_status;
    battery_converter_warning_status_t  battery_converter_warning;
    bmc_pcs_status_t                    bmc_pcs_status;
    bmc_command_to_pcs_t                bmc_command_to_pcs;
    precharge_relay_status_t            precharge_relay_status;
    main_relay_status_t                 main_relay_status;

    const uint16_t PACKET_LENGTH = 68;
    char buffer[68];

};

#endif // DATA_GROUP_H
