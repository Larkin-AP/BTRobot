﻿#ifndef ROBOT_H_
#define ROBOT_H_

#include<memory>
#include<aris.hpp>


namespace robot
{
	//pos_offset记录的是极限位置上电后，prepare位置对应的电机位置
	static const double pos_offset[18] = {
            5,5,5,
			0,0,0,
			0,0,0,
			0,0,0,
			0,0,0,
			0,0,0
	};

    static const double home_offset[18]{
        -41.1344,
        -24.8798,
        -5.15221,
        51.7326,
        -40.0003,
        6.4277,
        7.79429,
        -42.2623,
        20.2287,
        10.0233,
        -39.9234,
        27.1795,
        -15.5258,
        -40.1103,
        -11.7967,
        12.2192,
        -40.0349,
        18.826

    };

	//---------------------读取当前电机的位置--------------------//
	class ReadCurrentPos :public aris::core::CloneObject<ReadCurrentPos, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~ReadCurrentPos();
		explicit ReadCurrentPos(const std::string& name = "Read");
	};


    //---------------------test,single motor cos move----------------//
    //极限位置上电，
    class Test :public aris::core::CloneObject<Test, aris::plan::Plan>
    {
    public:
        auto virtual prepareNrt()->void;
        auto virtual executeRT()->int;
        auto virtual collectNrt()->void;

        virtual ~Test();
        explicit Test(const std::string& name = "Test");

    };


    //设立腿1末端初始位置
    class SetInitPos :public aris::core::CloneObject<SetInitPos, aris::plan::Plan>
    {
    public:
        auto virtual prepareNrt()->void;
        auto virtual executeRT()->int;
        auto virtual collectNrt()->void;

        virtual ~SetInitPos();
        explicit SetInitPos(const std::string& name = "setInitPos");

        auto calculateInitPos()->void; //根据腿1末端坐标来计算其他其他腿坐标从而确定foot_start_pos


    private:
        double x_in_leg1_frame_;
        double y_in_leg1_frame_;
        double z_in_leg1_frame_;

    };




    //---------------------从任意位置移动到prepare位置----------------//
    //在零位上电
    class Prepare :public aris::core::CloneObject<Prepare, aris::plan::Plan>
    {
    public:
        auto virtual prepareNrt()->void;
        auto virtual executeRT()->int;
        auto virtual collectNrt()->void;

        virtual ~Prepare();
        explicit Prepare(const std::string& name = "prepare");

    };

	//-------------------每个电机简单性能测试（梯形曲线移动）-------------------//
		class MoveJointAll :public aris::core::CloneObject<MoveJointAll, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~MoveJointAll();
		explicit MoveJointAll(const std::string& name = "moveJA");
	private:
        double dir_;
        double len_;
		
	};

	//-------------------每个电机简单性能测试（梯形曲线移动）-------------------//
	class MoveJointAllCos :public aris::core::CloneObject<MoveJointAllCos, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~MoveJointAllCos();
		explicit MoveJointAllCos(const std::string& name = "moveJAC");
	private:
		double cef_;

	};



	//-------------------驱动   前进后退-------------------//
	class HexForward :public aris::core::CloneObject<HexForward, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~HexForward();
		explicit HexForward(const std::string& name = "forward");
	private:
		double x_step_;
		int n_;
	};

	//-------------------驱动   左右移动-------------------//
	class HexLateral :public aris::core::CloneObject<HexLateral, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~HexLateral();
		explicit HexLateral(const std::string& name = "lateral");
	private:
		double z_step_;
		int n_;
	};

	//-------------------驱动   左右转动-------------------//
	class HexTurn :public aris::core::CloneObject<HexTurn, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~HexTurn();
		explicit HexTurn(const std::string& name = "turn");
	private:
		double turn_yaw_;
		int n_;
	};

	//-------------------驱动   四足步态-------------------//
	class HexTetrapod :public aris::core::CloneObject<HexTetrapod, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~HexTetrapod();
		explicit HexTetrapod(const std::string& name = "turn");
	private:
		double x_step_;
		int n_;
	};




    //  驅動----指定單腿坐標
    class SingleLegEndCoordinate :public aris::core::CloneObject<SingleLegEndCoordinate, aris::plan::Plan>
    {
    public:
        auto virtual prepareNrt()->void;
        auto virtual executeRT()->int;
        auto virtual collectNrt()->void;

        virtual ~SingleLegEndCoordinate();
        explicit SingleLegEndCoordinate(const std::string& name = "turn");
    private:
        double x_coord_;
        double y_coord_;
        double z_coord_;
    };




	//--------------------测试TCurve2-----------------------//
	class TCurve2Test :public aris::core::CloneObject<TCurve2Test, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;
		auto virtual collectNrt()->void;

		virtual ~TCurve2Test();
		explicit TCurve2Test(const std::string& name = "test");

	};


	


	class HexRead :public aris::core::CloneObject<HexRead, aris::plan::Plan>
	{
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int;

		virtual ~HexRead();
		explicit HexRead(const std::string& name = "HexRead");
	private:
		double turn_angle_;
	};
	//前进
	class HexDynamicForwardTest :public aris::core::CloneObject<HexDynamicForwardTest, aris::plan::Plan> {
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int override;

		virtual ~HexDynamicForwardTest();
		explicit HexDynamicForwardTest(const std::string& name = "hex_forward");
	};
	//后退
	class HexDynamicBackTest :public aris::core::CloneObject<HexDynamicBackTest, aris::plan::Plan> {
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int override;

		virtual ~HexDynamicBackTest();
		explicit HexDynamicBackTest(const std::string& name = "hex_back");
	};
	//右移
	class HexDynamicRightTest :public aris::core::CloneObject<HexDynamicRightTest, aris::plan::Plan> {
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int override;

		virtual ~HexDynamicRightTest();
		explicit HexDynamicRightTest(const std::string& name = "hex_right");
	};
	//左移
	class HexDynamicLeftTest :public aris::core::CloneObject<HexDynamicLeftTest, aris::plan::Plan> {
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int override;

		virtual ~HexDynamicLeftTest();
		explicit HexDynamicLeftTest(const std::string& name = "hex_left");
	};
	//右转
	class HexDynamicTurnRightTest :public aris::core::CloneObject<HexDynamicTurnRightTest, aris::plan::Plan> {
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int override;

		virtual ~HexDynamicTurnRightTest();
		explicit HexDynamicTurnRightTest(const std::string& name = "hex_turn_right");
	};

	//左转
	class HexDynamicTurnLeftTest :public aris::core::CloneObject<HexDynamicTurnLeftTest, aris::plan::Plan> {
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int override;

		virtual ~HexDynamicTurnLeftTest();
		explicit HexDynamicTurnLeftTest(const std::string& name = "hex_turn_left");
	};

	//四足步态
	class HexDynamicTetrapodTest :public aris::core::CloneObject<HexDynamicTetrapodTest, aris::plan::Plan> {
	public:
		auto virtual prepareNrt()->void;
		auto virtual executeRT()->int override;

		virtual ~HexDynamicTetrapodTest();
		explicit HexDynamicTetrapodTest(const std::string& name = "hex_tetrapod");
	};





	auto createModelHexapod()->std::unique_ptr<aris::dynamic::Model>;
	auto createControllerHexapod()->std::unique_ptr<aris::control::Controller>;
	auto createPlanHexapod()->std::unique_ptr<aris::plan::PlanRoot>;

}
#endif
