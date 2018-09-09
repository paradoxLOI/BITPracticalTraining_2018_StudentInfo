# BITPracticalTraining_2018_StudentInfo

作者：孙之问（paradoxLOI@163.com)	日期：2018/09/09 19:02:21

项目：StudentInfo（https://github.com/paradoxLOI/BITPracticalTraining_2018_StudentInfo）

## 项目简介

### 开发环境

- 操作系统：Windows 10 1803
- IDE:	  VisualStudio 2017 community（v141工具集，后改为v100工具集，如果出现运行问题请检查工具集版本）
- 可视窗口：MFC

### 项目功能

学生信息统计，采集学生的姓名、学号、性别、出生日期、照片、专业并把除照片外的信息存储到txt文件。（照片要求从文件导入，专业设置先选取学院再选取其下的专业）。

### 使用说明

性别选择采用Radio Button控件，保证为性别选项为单选。

出生日期初始状态禁用月、日Combo控件，在选择年Combo控件后解禁月Combo控件，在选择月Combo控件后才能确定当月天数（28天/29天/30天/31天）以解禁日Combo控件。

专业选择请点击选择专业按钮，在弹出对话框中选择专业，专业Edit控件为ReadOnly不支持直接写入。

因开发环境中未配置OpenCV环境，选择照片不支持除bmp格式之外的文件格式，请选择bmp矢量图格式。

在填完全部信息后请点击确定以保存学生信息，如果未全部填写将会提示并跳过保存操作。

点击重置按钮将清空所有填入信息，请谨慎操作。

## TODO List

- [ ] 增添PictureControl控件对其他图片格式的支持
- [x] 增加对保存信息前对信息完整性的检查
- [x] 修改每月天数与月份年份相匹配