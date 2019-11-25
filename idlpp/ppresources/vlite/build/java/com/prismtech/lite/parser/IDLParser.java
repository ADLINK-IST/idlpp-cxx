// Generated from IDL.g4 by ANTLR 4.4
package com.prismtech.lite.parser;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class IDLParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.4", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		CODEPOS=1, INTEGER_LITERAL=2, OCTAL_LITERAL=3, HEX_LITERAL=4, FLOATING_PT_LITERAL=5, 
		FIXED_PT_LITERAL=6, WIDE_CHARACTER_LITERAL=7, CHARACTER_LITERAL=8, WIDE_STRING_LITERAL=9, 
		STRING_LITERAL=10, BOOLEAN_LITERAL=11, SEMICOLON=12, COLON=13, COMA=14, 
		LEFT_BRACE=15, RIGHT_BRACE=16, LEFT_BRACKET=17, RIGHT_BRACKET=18, LEFT_SQUARE_BRACKET=19, 
		RIGHT_SQUARE_BRACKET=20, TILDE=21, SLASH=22, LEFT_ANG_BRACKET=23, RIGHT_ANG_BRACKET=24, 
		STAR=25, PLUS=26, MINUS=27, CARET=28, AMPERSAND=29, PIPE=30, EQUAL=31, 
		PERCENT=32, NUMSIGN=33, DOUBLE_COLON=34, RIGHT_SHIFT=35, LEFT_SHIFT=36, 
		KW_SETRAISES=37, KW_OUT=38, KW_EMITS=39, KW_STRING=40, KW_SWITCH=41, KW_PUBLISHES=42, 
		KW_TYPEDEF=43, KW_USES=44, KW_PRIMARYKEY=45, KW_CUSTOM=46, KW_OCTET=47, 
		KW_SEQUENCE=48, KW_IMPORT=49, KW_STRUCT=50, KW_NATIVE=51, KW_READONLY=52, 
		KW_FINDER=53, KW_RAISES=54, KW_VOID=55, KW_PRIVATE=56, KW_EVENTTYPE=57, 
		KW_WCHAR=58, KW_IN=59, KW_DEFAULT=60, KW_PUBLIC=61, KW_SHORT=62, KW_LONG=63, 
		KW_ENUM=64, KW_WSTRING=65, KW_CONTEXT=66, KW_HOME=67, KW_FACTORY=68, KW_EXCEPTION=69, 
		KW_GETRAISES=70, KW_CONST=71, KW_VALUEBASE=72, KW_VALUETYPE=73, KW_SUPPORTS=74, 
		KW_MODULE=75, KW_OBJECT=76, KW_TRUNCATABLE=77, KW_UNSIGNED=78, KW_FIXED=79, 
		KW_UNION=80, KW_ONEWAY=81, KW_ANY=82, KW_CHAR=83, KW_CASE=84, KW_FLOAT=85, 
		KW_BOOLEAN=86, KW_MULTIPLE=87, KW_ABSTRACT=88, KW_INOUT=89, KW_PROVIDES=90, 
		KW_CONSUMES=91, KW_DOUBLE=92, KW_TYPEPREFIX=93, KW_TYPEID=94, KW_ATTRIBUTE=95, 
		KW_LOCAL=96, KW_MANAGES=97, KW_INTERFACE=98, KW_COMPONENT=99, ID=100, 
		WS=101, COMMENT=102, LINE_COMMENT=103, LINE_PRAGMA=104;
	public static final String[] tokenNames = {
		"<INVALID>", "CODEPOS", "INTEGER_LITERAL", "OCTAL_LITERAL", "HEX_LITERAL", 
		"FLOATING_PT_LITERAL", "FIXED_PT_LITERAL", "WIDE_CHARACTER_LITERAL", "CHARACTER_LITERAL", 
		"WIDE_STRING_LITERAL", "STRING_LITERAL", "BOOLEAN_LITERAL", "';'", "':'", 
		"','", "'{'", "'}'", "'('", "')'", "'['", "']'", "'~'", "'/'", "'<'", 
		"'>'", "'*'", "'+'", "'-'", "'^'", "'&'", "'|'", "'='", "'%'", "'#'", 
		"'::'", "'>>'", "'<<'", "'setraises'", "'out'", "'emits'", "'string'", 
		"'switch'", "'publishes'", "'typedef'", "'uses'", "'primarykey'", "'custom'", 
		"'octet'", "'sequence'", "'import'", "'struct'", "'native'", "'readonly'", 
		"'finder'", "'raises'", "'void'", "'private'", "'eventtype'", "'wchar'", 
		"'in'", "'default'", "'public'", "'short'", "'long'", "'enum'", "'wstring'", 
		"'context'", "'home'", "'factory'", "'exception'", "'getraises'", "'const'", 
		"'ValueBase'", "'valuetype'", "'supports'", "'module'", "'Object'", "'truncatable'", 
		"'unsigned'", "'fixed'", "'union'", "'oneway'", "'any'", "'char'", "'case'", 
		"'float'", "'boolean'", "'multiple'", "'abstract'", "'inout'", "'provides'", 
		"'consumes'", "'double'", "'typeprefix'", "'typeid'", "'attribute'", "'local'", 
		"'manages'", "'interface'", "'component'", "ID", "WS", "COMMENT", "LINE_COMMENT", 
		"LINE_PRAGMA"
	};
	public static final int
		RULE_specification = 0, RULE_definition = 1, RULE_module = 2, RULE_interface_or_forward_decl = 3, 
		RULE_interface_decl = 4, RULE_forward_decl = 5, RULE_interface_header = 6, 
		RULE_interface_body = 7, RULE_export = 8, RULE_interface_inheritance_spec = 9, 
		RULE_interface_name = 10, RULE_scoped_name = 11, RULE_value = 12, RULE_value_forward_decl = 13, 
		RULE_value_box_decl = 14, RULE_value_abs_decl = 15, RULE_value_decl = 16, 
		RULE_value_header = 17, RULE_value_inheritance_spec = 18, RULE_value_name = 19, 
		RULE_value_element = 20, RULE_state_member = 21, RULE_init_decl = 22, 
		RULE_init_param_decls = 23, RULE_init_param_decl = 24, RULE_init_param_attribute = 25, 
		RULE_const_decl = 26, RULE_const_type = 27, RULE_const_exp = 28, RULE_or_expr = 29, 
		RULE_xor_expr = 30, RULE_and_expr = 31, RULE_shift_expr = 32, RULE_add_expr = 33, 
		RULE_mult_expr = 34, RULE_unary_expr = 35, RULE_unary_operator = 36, RULE_primary_expr = 37, 
		RULE_literal = 38, RULE_positive_int_const = 39, RULE_type_decl = 40, 
		RULE_type_declarator = 41, RULE_type_spec = 42, RULE_simple_type_spec = 43, 
		RULE_base_type_spec = 44, RULE_template_type_spec = 45, RULE_constr_type_spec = 46, 
		RULE_declarators = 47, RULE_declarator = 48, RULE_simple_declarator = 49, 
		RULE_complex_declarator = 50, RULE_floating_pt_type = 51, RULE_integer_type = 52, 
		RULE_signed_int = 53, RULE_signed_short_int = 54, RULE_signed_long_int = 55, 
		RULE_signed_longlong_int = 56, RULE_unsigned_int = 57, RULE_unsigned_short_int = 58, 
		RULE_unsigned_long_int = 59, RULE_unsigned_longlong_int = 60, RULE_char_type = 61, 
		RULE_wide_char_type = 62, RULE_boolean_type = 63, RULE_octet_type = 64, 
		RULE_any_type = 65, RULE_object_type = 66, RULE_struct_type = 67, RULE_member_list = 68, 
		RULE_member = 69, RULE_union_type = 70, RULE_switch_type_spec = 71, RULE_switch_body = 72, 
		RULE_case_stmt = 73, RULE_case_label = 74, RULE_element_spec = 75, RULE_enum_type = 76, 
		RULE_enumerator = 77, RULE_sequence_type = 78, RULE_string_type = 79, 
		RULE_wide_string_type = 80, RULE_array_declarator = 81, RULE_fixed_array_size = 82, 
		RULE_attr_decl = 83, RULE_except_decl = 84, RULE_op_decl = 85, RULE_op_attribute = 86, 
		RULE_op_type_spec = 87, RULE_parameter_decls = 88, RULE_param_decl = 89, 
		RULE_param_attribute = 90, RULE_raises_expr = 91, RULE_context_expr = 92, 
		RULE_param_type_spec = 93, RULE_fixed_pt_type = 94, RULE_fixed_pt_const_type = 95, 
		RULE_value_base_type = 96, RULE_constr_forward_decl = 97, RULE_import_decl = 98, 
		RULE_imported_scope = 99, RULE_type_id_decl = 100, RULE_type_prefix_decl = 101, 
		RULE_readonly_attr_spec = 102, RULE_readonly_attr_declarator = 103, RULE_attr_spec = 104, 
		RULE_attr_declarator = 105, RULE_attr_raises_expr = 106, RULE_get_excep_expr = 107, 
		RULE_set_excep_expr = 108, RULE_exception_list = 109, RULE_component = 110, 
		RULE_component_forward_decl = 111, RULE_component_decl = 112, RULE_component_header = 113, 
		RULE_supported_interface_spec = 114, RULE_component_inheritance_spec = 115, 
		RULE_component_body = 116, RULE_component_export = 117, RULE_provides_decl = 118, 
		RULE_interface_type = 119, RULE_uses_decl = 120, RULE_emits_decl = 121, 
		RULE_publishes_decl = 122, RULE_consumes_decl = 123, RULE_home_decl = 124, 
		RULE_home_header = 125, RULE_home_inheritance_spec = 126, RULE_primary_key_spec = 127, 
		RULE_home_body = 128, RULE_home_export = 129, RULE_factory_decl = 130, 
		RULE_finder_decl = 131, RULE_event = 132, RULE_event_forward_decl = 133, 
		RULE_event_abs_decl = 134, RULE_event_decl = 135, RULE_event_header = 136, 
		RULE_pragma_decl = 137, RULE_codepos_decl = 138;
	public static final String[] ruleNames = {
		"specification", "definition", "module", "interface_or_forward_decl", 
		"interface_decl", "forward_decl", "interface_header", "interface_body", 
		"export", "interface_inheritance_spec", "interface_name", "scoped_name", 
		"value", "value_forward_decl", "value_box_decl", "value_abs_decl", "value_decl", 
		"value_header", "value_inheritance_spec", "value_name", "value_element", 
		"state_member", "init_decl", "init_param_decls", "init_param_decl", "init_param_attribute", 
		"const_decl", "const_type", "const_exp", "or_expr", "xor_expr", "and_expr", 
		"shift_expr", "add_expr", "mult_expr", "unary_expr", "unary_operator", 
		"primary_expr", "literal", "positive_int_const", "type_decl", "type_declarator", 
		"type_spec", "simple_type_spec", "base_type_spec", "template_type_spec", 
		"constr_type_spec", "declarators", "declarator", "simple_declarator", 
		"complex_declarator", "floating_pt_type", "integer_type", "signed_int", 
		"signed_short_int", "signed_long_int", "signed_longlong_int", "unsigned_int", 
		"unsigned_short_int", "unsigned_long_int", "unsigned_longlong_int", "char_type", 
		"wide_char_type", "boolean_type", "octet_type", "any_type", "object_type", 
		"struct_type", "member_list", "member", "union_type", "switch_type_spec", 
		"switch_body", "case_stmt", "case_label", "element_spec", "enum_type", 
		"enumerator", "sequence_type", "string_type", "wide_string_type", "array_declarator", 
		"fixed_array_size", "attr_decl", "except_decl", "op_decl", "op_attribute", 
		"op_type_spec", "parameter_decls", "param_decl", "param_attribute", "raises_expr", 
		"context_expr", "param_type_spec", "fixed_pt_type", "fixed_pt_const_type", 
		"value_base_type", "constr_forward_decl", "import_decl", "imported_scope", 
		"type_id_decl", "type_prefix_decl", "readonly_attr_spec", "readonly_attr_declarator", 
		"attr_spec", "attr_declarator", "attr_raises_expr", "get_excep_expr", 
		"set_excep_expr", "exception_list", "component", "component_forward_decl", 
		"component_decl", "component_header", "supported_interface_spec", "component_inheritance_spec", 
		"component_body", "component_export", "provides_decl", "interface_type", 
		"uses_decl", "emits_decl", "publishes_decl", "consumes_decl", "home_decl", 
		"home_header", "home_inheritance_spec", "primary_key_spec", "home_body", 
		"home_export", "factory_decl", "finder_decl", "event", "event_forward_decl", 
		"event_abs_decl", "event_decl", "event_header", "pragma_decl", "codepos_decl"
	};

	@Override
	public String getGrammarFileName() { return "IDL.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public IDLParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class SpecificationContext extends ParserRuleContext {
		public List<DefinitionContext> definition() {
			return getRuleContexts(DefinitionContext.class);
		}
		public DefinitionContext definition(int i) {
			return getRuleContext(DefinitionContext.class,i);
		}
		public Import_declContext import_decl(int i) {
			return getRuleContext(Import_declContext.class,i);
		}
		public List<Import_declContext> import_decl() {
			return getRuleContexts(Import_declContext.class);
		}
		public SpecificationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_specification; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSpecification(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SpecificationContext specification() throws RecognitionException {
		SpecificationContext _localctx = new SpecificationContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_specification);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(281);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==KW_IMPORT) {
				{
				{
				setState(278); import_decl();
				}
				}
				setState(283);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(285); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(284); definition();
				}
				}
				setState(287); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << CODEPOS) | (1L << KW_TYPEDEF) | (1L << KW_CUSTOM) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_EVENTTYPE))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_HOME - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUETYPE - 64)) | (1L << (KW_MODULE - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ABSTRACT - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_LOCAL - 64)) | (1L << (KW_INTERFACE - 64)) | (1L << (KW_COMPONENT - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DefinitionContext extends ParserRuleContext {
		public Const_declContext const_decl() {
			return getRuleContext(Const_declContext.class,0);
		}
		public Home_declContext home_decl() {
			return getRuleContext(Home_declContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public Except_declContext except_decl() {
			return getRuleContext(Except_declContext.class,0);
		}
		public Type_prefix_declContext type_prefix_decl() {
			return getRuleContext(Type_prefix_declContext.class,0);
		}
		public Interface_or_forward_declContext interface_or_forward_decl() {
			return getRuleContext(Interface_or_forward_declContext.class,0);
		}
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public Pragma_declContext pragma_decl() {
			return getRuleContext(Pragma_declContext.class,0);
		}
		public ModuleContext module() {
			return getRuleContext(ModuleContext.class,0);
		}
		public Type_id_declContext type_id_decl() {
			return getRuleContext(Type_id_declContext.class,0);
		}
		public ComponentContext component() {
			return getRuleContext(ComponentContext.class,0);
		}
		public Type_declContext type_decl() {
			return getRuleContext(Type_declContext.class,0);
		}
		public Codepos_declContext codepos_decl() {
			return getRuleContext(Codepos_declContext.class,0);
		}
		public EventContext event() {
			return getRuleContext(EventContext.class,0);
		}
		public DefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_definition; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitDefinition(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DefinitionContext definition() throws RecognitionException {
		DefinitionContext _localctx = new DefinitionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_definition);
		try {
			setState(324);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(289); type_decl();
				setState(290); match(SEMICOLON);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(292); const_decl();
				setState(293); match(SEMICOLON);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(295); except_decl();
				setState(296); match(SEMICOLON);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(298); interface_or_forward_decl();
				setState(299); match(SEMICOLON);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(301); module();
				setState(302); match(SEMICOLON);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(304); value();
				setState(305); match(SEMICOLON);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(307); type_id_decl();
				setState(308); match(SEMICOLON);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(310); type_prefix_decl();
				setState(311); match(SEMICOLON);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(313); event();
				setState(314); match(SEMICOLON);
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(316); component();
				setState(317); match(SEMICOLON);
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(319); home_decl();
				setState(320); match(SEMICOLON);
				}
				break;
			case 12:
				enterOuterAlt(_localctx, 12);
				{
				setState(322); pragma_decl();
				}
				break;
			case 13:
				enterOuterAlt(_localctx, 13);
				{
				setState(323); codepos_decl();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ModuleContext extends ParserRuleContext {
		public List<DefinitionContext> definition() {
			return getRuleContexts(DefinitionContext.class);
		}
		public DefinitionContext definition(int i) {
			return getRuleContext(DefinitionContext.class,i);
		}
		public TerminalNode KW_MODULE() { return getToken(IDLParser.KW_MODULE, 0); }
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public ModuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitModule(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ModuleContext module() throws RecognitionException {
		ModuleContext _localctx = new ModuleContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_module);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(326); match(KW_MODULE);
			setState(327); match(ID);
			setState(328); match(LEFT_BRACE);
			setState(330); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(329); definition();
				}
				}
				setState(332); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << CODEPOS) | (1L << KW_TYPEDEF) | (1L << KW_CUSTOM) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_EVENTTYPE))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_HOME - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUETYPE - 64)) | (1L << (KW_MODULE - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ABSTRACT - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_LOCAL - 64)) | (1L << (KW_INTERFACE - 64)) | (1L << (KW_COMPONENT - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0) );
			setState(334); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_or_forward_declContext extends ParserRuleContext {
		public Forward_declContext forward_decl() {
			return getRuleContext(Forward_declContext.class,0);
		}
		public Interface_declContext interface_decl() {
			return getRuleContext(Interface_declContext.class,0);
		}
		public Interface_or_forward_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_or_forward_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInterface_or_forward_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Interface_or_forward_declContext interface_or_forward_decl() throws RecognitionException {
		Interface_or_forward_declContext _localctx = new Interface_or_forward_declContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_interface_or_forward_decl);
		try {
			setState(338);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(336); interface_decl();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(337); forward_decl();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_declContext extends ParserRuleContext {
		public Interface_bodyContext interface_body() {
			return getRuleContext(Interface_bodyContext.class,0);
		}
		public Interface_headerContext interface_header() {
			return getRuleContext(Interface_headerContext.class,0);
		}
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Interface_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInterface_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Interface_declContext interface_decl() throws RecognitionException {
		Interface_declContext _localctx = new Interface_declContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_interface_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(340); interface_header();
			setState(341); match(LEFT_BRACE);
			setState(342); interface_body();
			setState(343); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Forward_declContext extends ParserRuleContext {
		public TerminalNode KW_INTERFACE() { return getToken(IDLParser.KW_INTERFACE, 0); }
		public TerminalNode KW_ABSTRACT() { return getToken(IDLParser.KW_ABSTRACT, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_LOCAL() { return getToken(IDLParser.KW_LOCAL, 0); }
		public Forward_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forward_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitForward_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Forward_declContext forward_decl() throws RecognitionException {
		Forward_declContext _localctx = new Forward_declContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_forward_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(346);
			_la = _input.LA(1);
			if (_la==KW_ABSTRACT || _la==KW_LOCAL) {
				{
				setState(345);
				_la = _input.LA(1);
				if ( !(_la==KW_ABSTRACT || _la==KW_LOCAL) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				}
			}

			setState(348); match(KW_INTERFACE);
			setState(349); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_headerContext extends ParserRuleContext {
		public Interface_inheritance_specContext interface_inheritance_spec() {
			return getRuleContext(Interface_inheritance_specContext.class,0);
		}
		public TerminalNode KW_INTERFACE() { return getToken(IDLParser.KW_INTERFACE, 0); }
		public TerminalNode KW_ABSTRACT() { return getToken(IDLParser.KW_ABSTRACT, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_LOCAL() { return getToken(IDLParser.KW_LOCAL, 0); }
		public Interface_headerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_header; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInterface_header(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Interface_headerContext interface_header() throws RecognitionException {
		Interface_headerContext _localctx = new Interface_headerContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_interface_header);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(352);
			_la = _input.LA(1);
			if (_la==KW_ABSTRACT || _la==KW_LOCAL) {
				{
				setState(351);
				_la = _input.LA(1);
				if ( !(_la==KW_ABSTRACT || _la==KW_LOCAL) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				}
			}

			setState(354); match(KW_INTERFACE);
			setState(355); match(ID);
			setState(357);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(356); interface_inheritance_spec();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_bodyContext extends ParserRuleContext {
		public ExportContext export(int i) {
			return getRuleContext(ExportContext.class,i);
		}
		public List<ExportContext> export() {
			return getRuleContexts(ExportContext.class);
		}
		public Interface_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_body; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInterface_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Interface_bodyContext interface_body() throws RecognitionException {
		Interface_bodyContext _localctx = new Interface_bodyContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_interface_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(362);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_TYPEDEF) | (1L << KW_OCTET) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_READONLY) | (1L << KW_VOID) | (1L << KW_WCHAR) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ONEWAY - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_ATTRIBUTE - 64)) | (1L << (ID - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0)) {
				{
				{
				setState(359); export();
				}
				}
				setState(364);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExportContext extends ParserRuleContext {
		public Const_declContext const_decl() {
			return getRuleContext(Const_declContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public Except_declContext except_decl() {
			return getRuleContext(Except_declContext.class,0);
		}
		public Pragma_declContext pragma_decl() {
			return getRuleContext(Pragma_declContext.class,0);
		}
		public Op_declContext op_decl() {
			return getRuleContext(Op_declContext.class,0);
		}
		public Attr_declContext attr_decl() {
			return getRuleContext(Attr_declContext.class,0);
		}
		public Type_id_declContext type_id_decl() {
			return getRuleContext(Type_id_declContext.class,0);
		}
		public Type_prefix_declContext type_prefix_decl() {
			return getRuleContext(Type_prefix_declContext.class,0);
		}
		public Type_declContext type_decl() {
			return getRuleContext(Type_declContext.class,0);
		}
		public ExportContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_export; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitExport(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExportContext export() throws RecognitionException {
		ExportContext _localctx = new ExportContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_export);
		try {
			setState(387);
			switch (_input.LA(1)) {
			case KW_TYPEDEF:
			case KW_STRUCT:
			case KW_NATIVE:
			case KW_ENUM:
			case KW_UNION:
				enterOuterAlt(_localctx, 1);
				{
				setState(365); type_decl();
				setState(366); match(SEMICOLON);
				}
				break;
			case KW_CONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(368); const_decl();
				setState(369); match(SEMICOLON);
				}
				break;
			case KW_EXCEPTION:
				enterOuterAlt(_localctx, 3);
				{
				setState(371); except_decl();
				setState(372); match(SEMICOLON);
				}
				break;
			case KW_READONLY:
			case KW_ATTRIBUTE:
				enterOuterAlt(_localctx, 4);
				{
				setState(374); attr_decl();
				setState(375); match(SEMICOLON);
				}
				break;
			case DOUBLE_COLON:
			case KW_STRING:
			case KW_OCTET:
			case KW_VOID:
			case KW_WCHAR:
			case KW_SHORT:
			case KW_LONG:
			case KW_WSTRING:
			case KW_VALUEBASE:
			case KW_OBJECT:
			case KW_UNSIGNED:
			case KW_ONEWAY:
			case KW_ANY:
			case KW_CHAR:
			case KW_FLOAT:
			case KW_BOOLEAN:
			case KW_DOUBLE:
			case ID:
				enterOuterAlt(_localctx, 5);
				{
				setState(377); op_decl();
				setState(378); match(SEMICOLON);
				}
				break;
			case KW_TYPEID:
				enterOuterAlt(_localctx, 6);
				{
				setState(380); type_id_decl();
				setState(381); match(SEMICOLON);
				}
				break;
			case KW_TYPEPREFIX:
				enterOuterAlt(_localctx, 7);
				{
				setState(383); type_prefix_decl();
				setState(384); match(SEMICOLON);
				}
				break;
			case LINE_PRAGMA:
				enterOuterAlt(_localctx, 8);
				{
				setState(386); pragma_decl();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_inheritance_specContext extends ParserRuleContext {
		public List<Interface_nameContext> interface_name() {
			return getRuleContexts(Interface_nameContext.class);
		}
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public Interface_nameContext interface_name(int i) {
			return getRuleContext(Interface_nameContext.class,i);
		}
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public TerminalNode COLON() { return getToken(IDLParser.COLON, 0); }
		public Interface_inheritance_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_inheritance_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInterface_inheritance_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Interface_inheritance_specContext interface_inheritance_spec() throws RecognitionException {
		Interface_inheritance_specContext _localctx = new Interface_inheritance_specContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_interface_inheritance_spec);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(389); match(COLON);
			setState(390); interface_name();
			setState(395);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(391); match(COMA);
				setState(392); interface_name();
				}
				}
				setState(397);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_nameContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public Interface_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_name; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInterface_name(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Interface_nameContext interface_name() throws RecognitionException {
		Interface_nameContext _localctx = new Interface_nameContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_interface_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(398); scoped_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Scoped_nameContext extends ParserRuleContext {
		public TerminalNode DOUBLE_COLON(int i) {
			return getToken(IDLParser.DOUBLE_COLON, i);
		}
		public List<TerminalNode> ID() { return getTokens(IDLParser.ID); }
		public List<TerminalNode> DOUBLE_COLON() { return getTokens(IDLParser.DOUBLE_COLON); }
		public TerminalNode ID(int i) {
			return getToken(IDLParser.ID, i);
		}
		public Scoped_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scoped_name; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitScoped_name(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Scoped_nameContext scoped_name() throws RecognitionException {
		Scoped_nameContext _localctx = new Scoped_nameContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_scoped_name);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(401);
			_la = _input.LA(1);
			if (_la==DOUBLE_COLON) {
				{
				setState(400); match(DOUBLE_COLON);
				}
			}

			setState(403); match(ID);
			setState(408);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==DOUBLE_COLON) {
				{
				{
				setState(404); match(DOUBLE_COLON);
				setState(405); match(ID);
				}
				}
				setState(410);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ValueContext extends ParserRuleContext {
		public Value_abs_declContext value_abs_decl() {
			return getRuleContext(Value_abs_declContext.class,0);
		}
		public Value_forward_declContext value_forward_decl() {
			return getRuleContext(Value_forward_declContext.class,0);
		}
		public Value_declContext value_decl() {
			return getRuleContext(Value_declContext.class,0);
		}
		public Value_box_declContext value_box_decl() {
			return getRuleContext(Value_box_declContext.class,0);
		}
		public ValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ValueContext value() throws RecognitionException {
		ValueContext _localctx = new ValueContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_value);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(415);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(411); value_decl();
				}
				break;
			case 2:
				{
				setState(412); value_abs_decl();
				}
				break;
			case 3:
				{
				setState(413); value_box_decl();
				}
				break;
			case 4:
				{
				setState(414); value_forward_decl();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_forward_declContext extends ParserRuleContext {
		public TerminalNode KW_ABSTRACT() { return getToken(IDLParser.KW_ABSTRACT, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_VALUETYPE() { return getToken(IDLParser.KW_VALUETYPE, 0); }
		public Value_forward_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_forward_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_forward_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_forward_declContext value_forward_decl() throws RecognitionException {
		Value_forward_declContext _localctx = new Value_forward_declContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_value_forward_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(418);
			_la = _input.LA(1);
			if (_la==KW_ABSTRACT) {
				{
				setState(417); match(KW_ABSTRACT);
				}
			}

			setState(420); match(KW_VALUETYPE);
			setState(421); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_box_declContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Type_specContext type_spec() {
			return getRuleContext(Type_specContext.class,0);
		}
		public TerminalNode KW_VALUETYPE() { return getToken(IDLParser.KW_VALUETYPE, 0); }
		public Value_box_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_box_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_box_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_box_declContext value_box_decl() throws RecognitionException {
		Value_box_declContext _localctx = new Value_box_declContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_value_box_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(423); match(KW_VALUETYPE);
			setState(424); match(ID);
			setState(425); type_spec();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_abs_declContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public ExportContext export(int i) {
			return getRuleContext(ExportContext.class,i);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_ABSTRACT() { return getToken(IDLParser.KW_ABSTRACT, 0); }
		public List<ExportContext> export() {
			return getRuleContexts(ExportContext.class);
		}
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Value_inheritance_specContext value_inheritance_spec() {
			return getRuleContext(Value_inheritance_specContext.class,0);
		}
		public TerminalNode KW_VALUETYPE() { return getToken(IDLParser.KW_VALUETYPE, 0); }
		public Value_abs_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_abs_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_abs_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_abs_declContext value_abs_decl() throws RecognitionException {
		Value_abs_declContext _localctx = new Value_abs_declContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_value_abs_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(427); match(KW_ABSTRACT);
			setState(428); match(KW_VALUETYPE);
			setState(429); match(ID);
			setState(430); value_inheritance_spec();
			setState(431); match(LEFT_BRACE);
			setState(435);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_TYPEDEF) | (1L << KW_OCTET) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_READONLY) | (1L << KW_VOID) | (1L << KW_WCHAR) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ONEWAY - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_ATTRIBUTE - 64)) | (1L << (ID - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0)) {
				{
				{
				setState(432); export();
				}
				}
				setState(437);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(438); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_declContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public Value_elementContext value_element(int i) {
			return getRuleContext(Value_elementContext.class,i);
		}
		public List<Value_elementContext> value_element() {
			return getRuleContexts(Value_elementContext.class);
		}
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Value_headerContext value_header() {
			return getRuleContext(Value_headerContext.class,0);
		}
		public Value_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_declContext value_decl() throws RecognitionException {
		Value_declContext _localctx = new Value_declContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_value_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(440); value_header();
			setState(441); match(LEFT_BRACE);
			setState(445);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_TYPEDEF) | (1L << KW_OCTET) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_READONLY) | (1L << KW_VOID) | (1L << KW_PRIVATE) | (1L << KW_WCHAR) | (1L << KW_PUBLIC) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_FACTORY - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ONEWAY - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_ATTRIBUTE - 64)) | (1L << (ID - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0)) {
				{
				{
				setState(442); value_element();
				}
				}
				setState(447);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(448); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_headerContext extends ParserRuleContext {
		public TerminalNode KW_CUSTOM() { return getToken(IDLParser.KW_CUSTOM, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Value_inheritance_specContext value_inheritance_spec() {
			return getRuleContext(Value_inheritance_specContext.class,0);
		}
		public TerminalNode KW_VALUETYPE() { return getToken(IDLParser.KW_VALUETYPE, 0); }
		public Value_headerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_header; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_header(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_headerContext value_header() throws RecognitionException {
		Value_headerContext _localctx = new Value_headerContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_value_header);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(451);
			_la = _input.LA(1);
			if (_la==KW_CUSTOM) {
				{
				setState(450); match(KW_CUSTOM);
				}
			}

			setState(453); match(KW_VALUETYPE);
			setState(454); match(ID);
			setState(455); value_inheritance_spec();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_inheritance_specContext extends ParserRuleContext {
		public TerminalNode KW_SUPPORTS() { return getToken(IDLParser.KW_SUPPORTS, 0); }
		public Value_nameContext value_name(int i) {
			return getRuleContext(Value_nameContext.class,i);
		}
		public List<Interface_nameContext> interface_name() {
			return getRuleContexts(Interface_nameContext.class);
		}
		public TerminalNode KW_TRUNCATABLE() { return getToken(IDLParser.KW_TRUNCATABLE, 0); }
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public Interface_nameContext interface_name(int i) {
			return getRuleContext(Interface_nameContext.class,i);
		}
		public List<Value_nameContext> value_name() {
			return getRuleContexts(Value_nameContext.class);
		}
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public TerminalNode COLON() { return getToken(IDLParser.COLON, 0); }
		public Value_inheritance_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_inheritance_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_inheritance_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_inheritance_specContext value_inheritance_spec() throws RecognitionException {
		Value_inheritance_specContext _localctx = new Value_inheritance_specContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_value_inheritance_spec);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(469);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(457); match(COLON);
				setState(459);
				_la = _input.LA(1);
				if (_la==KW_TRUNCATABLE) {
					{
					setState(458); match(KW_TRUNCATABLE);
					}
				}

				setState(461); value_name();
				setState(466);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMA) {
					{
					{
					setState(462); match(COMA);
					setState(463); value_name();
					}
					}
					setState(468);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(480);
			_la = _input.LA(1);
			if (_la==KW_SUPPORTS) {
				{
				setState(471); match(KW_SUPPORTS);
				setState(472); interface_name();
				setState(477);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMA) {
					{
					{
					setState(473); match(COMA);
					setState(474); interface_name();
					}
					}
					setState(479);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_nameContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public Value_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_name; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_name(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_nameContext value_name() throws RecognitionException {
		Value_nameContext _localctx = new Value_nameContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_value_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(482); scoped_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_elementContext extends ParserRuleContext {
		public Init_declContext init_decl() {
			return getRuleContext(Init_declContext.class,0);
		}
		public ExportContext export() {
			return getRuleContext(ExportContext.class,0);
		}
		public State_memberContext state_member() {
			return getRuleContext(State_memberContext.class,0);
		}
		public Value_elementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_element; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_element(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_elementContext value_element() throws RecognitionException {
		Value_elementContext _localctx = new Value_elementContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_value_element);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(487);
			switch (_input.LA(1)) {
			case DOUBLE_COLON:
			case KW_STRING:
			case KW_TYPEDEF:
			case KW_OCTET:
			case KW_STRUCT:
			case KW_NATIVE:
			case KW_READONLY:
			case KW_VOID:
			case KW_WCHAR:
			case KW_SHORT:
			case KW_LONG:
			case KW_ENUM:
			case KW_WSTRING:
			case KW_EXCEPTION:
			case KW_CONST:
			case KW_VALUEBASE:
			case KW_OBJECT:
			case KW_UNSIGNED:
			case KW_UNION:
			case KW_ONEWAY:
			case KW_ANY:
			case KW_CHAR:
			case KW_FLOAT:
			case KW_BOOLEAN:
			case KW_DOUBLE:
			case KW_TYPEPREFIX:
			case KW_TYPEID:
			case KW_ATTRIBUTE:
			case ID:
			case LINE_PRAGMA:
				{
				setState(484); export();
				}
				break;
			case KW_PRIVATE:
			case KW_PUBLIC:
				{
				setState(485); state_member();
				}
				break;
			case KW_FACTORY:
				{
				setState(486); init_decl();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class State_memberContext extends ParserRuleContext {
		public TerminalNode KW_PUBLIC() { return getToken(IDLParser.KW_PUBLIC, 0); }
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public DeclaratorsContext declarators() {
			return getRuleContext(DeclaratorsContext.class,0);
		}
		public TerminalNode KW_PRIVATE() { return getToken(IDLParser.KW_PRIVATE, 0); }
		public Type_specContext type_spec() {
			return getRuleContext(Type_specContext.class,0);
		}
		public State_memberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_state_member; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitState_member(this);
			else return visitor.visitChildren(this);
		}
	}

	public final State_memberContext state_member() throws RecognitionException {
		State_memberContext _localctx = new State_memberContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_state_member);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(489);
			_la = _input.LA(1);
			if ( !(_la==KW_PRIVATE || _la==KW_PUBLIC) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			setState(490); type_spec();
			setState(491); declarators();
			setState(492); match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Init_declContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public Raises_exprContext raises_expr() {
			return getRuleContext(Raises_exprContext.class,0);
		}
		public TerminalNode KW_FACTORY() { return getToken(IDLParser.KW_FACTORY, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Init_param_declsContext init_param_decls() {
			return getRuleContext(Init_param_declsContext.class,0);
		}
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public Init_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_init_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInit_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Init_declContext init_decl() throws RecognitionException {
		Init_declContext _localctx = new Init_declContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_init_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(494); match(KW_FACTORY);
			setState(495); match(ID);
			setState(496); match(LEFT_BRACKET);
			setState(498);
			_la = _input.LA(1);
			if (_la==KW_IN) {
				{
				setState(497); init_param_decls();
				}
			}

			setState(500); match(RIGHT_BRACKET);
			setState(502);
			_la = _input.LA(1);
			if (_la==KW_RAISES) {
				{
				setState(501); raises_expr();
				}
			}

			setState(504); match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Init_param_declsContext extends ParserRuleContext {
		public Init_param_declContext init_param_decl(int i) {
			return getRuleContext(Init_param_declContext.class,i);
		}
		public List<Init_param_declContext> init_param_decl() {
			return getRuleContexts(Init_param_declContext.class);
		}
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public Init_param_declsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_init_param_decls; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInit_param_decls(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Init_param_declsContext init_param_decls() throws RecognitionException {
		Init_param_declsContext _localctx = new Init_param_declsContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_init_param_decls);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(506); init_param_decl();
			setState(511);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(507); match(COMA);
				setState(508); init_param_decl();
				}
				}
				setState(513);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Init_param_declContext extends ParserRuleContext {
		public Init_param_attributeContext init_param_attribute() {
			return getRuleContext(Init_param_attributeContext.class,0);
		}
		public Param_type_specContext param_type_spec() {
			return getRuleContext(Param_type_specContext.class,0);
		}
		public Simple_declaratorContext simple_declarator() {
			return getRuleContext(Simple_declaratorContext.class,0);
		}
		public Init_param_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_init_param_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInit_param_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Init_param_declContext init_param_decl() throws RecognitionException {
		Init_param_declContext _localctx = new Init_param_declContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_init_param_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(514); init_param_attribute();
			setState(515); param_type_spec();
			setState(516); simple_declarator();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Init_param_attributeContext extends ParserRuleContext {
		public TerminalNode KW_IN() { return getToken(IDLParser.KW_IN, 0); }
		public Init_param_attributeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_init_param_attribute; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInit_param_attribute(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Init_param_attributeContext init_param_attribute() throws RecognitionException {
		Init_param_attributeContext _localctx = new Init_param_attributeContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_init_param_attribute);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(518); match(KW_IN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Const_declContext extends ParserRuleContext {
		public Const_typeContext const_type() {
			return getRuleContext(Const_typeContext.class,0);
		}
		public Const_expContext const_exp() {
			return getRuleContext(Const_expContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_CONST() { return getToken(IDLParser.KW_CONST, 0); }
		public TerminalNode EQUAL() { return getToken(IDLParser.EQUAL, 0); }
		public Const_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_const_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitConst_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Const_declContext const_decl() throws RecognitionException {
		Const_declContext _localctx = new Const_declContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_const_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(520); match(KW_CONST);
			setState(521); const_type();
			setState(522); match(ID);
			setState(523); match(EQUAL);
			setState(524); const_exp();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Const_typeContext extends ParserRuleContext {
		public Floating_pt_typeContext floating_pt_type() {
			return getRuleContext(Floating_pt_typeContext.class,0);
		}
		public Char_typeContext char_type() {
			return getRuleContext(Char_typeContext.class,0);
		}
		public String_typeContext string_type() {
			return getRuleContext(String_typeContext.class,0);
		}
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public Boolean_typeContext boolean_type() {
			return getRuleContext(Boolean_typeContext.class,0);
		}
		public Octet_typeContext octet_type() {
			return getRuleContext(Octet_typeContext.class,0);
		}
		public Fixed_pt_const_typeContext fixed_pt_const_type() {
			return getRuleContext(Fixed_pt_const_typeContext.class,0);
		}
		public Wide_string_typeContext wide_string_type() {
			return getRuleContext(Wide_string_typeContext.class,0);
		}
		public Wide_char_typeContext wide_char_type() {
			return getRuleContext(Wide_char_typeContext.class,0);
		}
		public Integer_typeContext integer_type() {
			return getRuleContext(Integer_typeContext.class,0);
		}
		public Const_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_const_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitConst_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Const_typeContext const_type() throws RecognitionException {
		Const_typeContext _localctx = new Const_typeContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_const_type);
		try {
			setState(536);
			switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(526); integer_type();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(527); char_type();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(528); wide_char_type();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(529); boolean_type();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(530); floating_pt_type();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(531); string_type();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(532); wide_string_type();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(533); fixed_pt_const_type();
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(534); scoped_name();
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(535); octet_type();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Const_expContext extends ParserRuleContext {
		public Or_exprContext or_expr() {
			return getRuleContext(Or_exprContext.class,0);
		}
		public Const_expContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_const_exp; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitConst_exp(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Const_expContext const_exp() throws RecognitionException {
		Const_expContext _localctx = new Const_expContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_const_exp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(538); or_expr();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Or_exprContext extends ParserRuleContext {
		public List<TerminalNode> PIPE() { return getTokens(IDLParser.PIPE); }
		public TerminalNode PIPE(int i) {
			return getToken(IDLParser.PIPE, i);
		}
		public List<Xor_exprContext> xor_expr() {
			return getRuleContexts(Xor_exprContext.class);
		}
		public Xor_exprContext xor_expr(int i) {
			return getRuleContext(Xor_exprContext.class,i);
		}
		public Or_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_or_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitOr_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Or_exprContext or_expr() throws RecognitionException {
		Or_exprContext _localctx = new Or_exprContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_or_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(540); xor_expr();
			setState(545);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==PIPE) {
				{
				{
				setState(541); match(PIPE);
				setState(542); xor_expr();
				}
				}
				setState(547);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Xor_exprContext extends ParserRuleContext {
		public List<And_exprContext> and_expr() {
			return getRuleContexts(And_exprContext.class);
		}
		public TerminalNode CARET(int i) {
			return getToken(IDLParser.CARET, i);
		}
		public List<TerminalNode> CARET() { return getTokens(IDLParser.CARET); }
		public And_exprContext and_expr(int i) {
			return getRuleContext(And_exprContext.class,i);
		}
		public Xor_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_xor_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitXor_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Xor_exprContext xor_expr() throws RecognitionException {
		Xor_exprContext _localctx = new Xor_exprContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_xor_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(548); and_expr();
			setState(553);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==CARET) {
				{
				{
				setState(549); match(CARET);
				setState(550); and_expr();
				}
				}
				setState(555);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class And_exprContext extends ParserRuleContext {
		public List<TerminalNode> AMPERSAND() { return getTokens(IDLParser.AMPERSAND); }
		public List<Shift_exprContext> shift_expr() {
			return getRuleContexts(Shift_exprContext.class);
		}
		public Shift_exprContext shift_expr(int i) {
			return getRuleContext(Shift_exprContext.class,i);
		}
		public TerminalNode AMPERSAND(int i) {
			return getToken(IDLParser.AMPERSAND, i);
		}
		public And_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_and_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitAnd_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final And_exprContext and_expr() throws RecognitionException {
		And_exprContext _localctx = new And_exprContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_and_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(556); shift_expr();
			setState(561);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==AMPERSAND) {
				{
				{
				setState(557); match(AMPERSAND);
				setState(558); shift_expr();
				}
				}
				setState(563);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Shift_exprContext extends ParserRuleContext {
		public TerminalNode LEFT_SHIFT(int i) {
			return getToken(IDLParser.LEFT_SHIFT, i);
		}
		public List<TerminalNode> LEFT_SHIFT() { return getTokens(IDLParser.LEFT_SHIFT); }
		public List<TerminalNode> RIGHT_SHIFT() { return getTokens(IDLParser.RIGHT_SHIFT); }
		public TerminalNode RIGHT_SHIFT(int i) {
			return getToken(IDLParser.RIGHT_SHIFT, i);
		}
		public List<Add_exprContext> add_expr() {
			return getRuleContexts(Add_exprContext.class);
		}
		public Add_exprContext add_expr(int i) {
			return getRuleContext(Add_exprContext.class,i);
		}
		public Shift_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shift_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitShift_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Shift_exprContext shift_expr() throws RecognitionException {
		Shift_exprContext _localctx = new Shift_exprContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_shift_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(564); add_expr();
			setState(569);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==RIGHT_SHIFT || _la==LEFT_SHIFT) {
				{
				{
				setState(565);
				_la = _input.LA(1);
				if ( !(_la==RIGHT_SHIFT || _la==LEFT_SHIFT) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				setState(566); add_expr();
				}
				}
				setState(571);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Add_exprContext extends ParserRuleContext {
		public TerminalNode MINUS(int i) {
			return getToken(IDLParser.MINUS, i);
		}
		public List<Mult_exprContext> mult_expr() {
			return getRuleContexts(Mult_exprContext.class);
		}
		public Mult_exprContext mult_expr(int i) {
			return getRuleContext(Mult_exprContext.class,i);
		}
		public List<TerminalNode> MINUS() { return getTokens(IDLParser.MINUS); }
		public List<TerminalNode> PLUS() { return getTokens(IDLParser.PLUS); }
		public TerminalNode PLUS(int i) {
			return getToken(IDLParser.PLUS, i);
		}
		public Add_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_add_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitAdd_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Add_exprContext add_expr() throws RecognitionException {
		Add_exprContext _localctx = new Add_exprContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_add_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(572); mult_expr();
			setState(577);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==PLUS || _la==MINUS) {
				{
				{
				setState(573);
				_la = _input.LA(1);
				if ( !(_la==PLUS || _la==MINUS) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				setState(574); mult_expr();
				}
				}
				setState(579);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Mult_exprContext extends ParserRuleContext {
		public TerminalNode SLASH(int i) {
			return getToken(IDLParser.SLASH, i);
		}
		public TerminalNode PERCENT(int i) {
			return getToken(IDLParser.PERCENT, i);
		}
		public List<TerminalNode> PERCENT() { return getTokens(IDLParser.PERCENT); }
		public List<Unary_exprContext> unary_expr() {
			return getRuleContexts(Unary_exprContext.class);
		}
		public Unary_exprContext unary_expr(int i) {
			return getRuleContext(Unary_exprContext.class,i);
		}
		public List<TerminalNode> SLASH() { return getTokens(IDLParser.SLASH); }
		public Mult_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mult_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitMult_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Mult_exprContext mult_expr() throws RecognitionException {
		Mult_exprContext _localctx = new Mult_exprContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_mult_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(580); unary_expr();
			setState(585);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SLASH) | (1L << STAR) | (1L << PERCENT))) != 0)) {
				{
				{
				setState(581);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SLASH) | (1L << STAR) | (1L << PERCENT))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				setState(582); unary_expr();
				}
				}
				setState(587);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unary_exprContext extends ParserRuleContext {
		public Primary_exprContext primary_expr() {
			return getRuleContext(Primary_exprContext.class,0);
		}
		public Unary_operatorContext unary_operator() {
			return getRuleContext(Unary_operatorContext.class,0);
		}
		public Unary_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUnary_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Unary_exprContext unary_expr() throws RecognitionException {
		Unary_exprContext _localctx = new Unary_exprContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_unary_expr);
		try {
			setState(592);
			switch (_input.LA(1)) {
			case TILDE:
			case PLUS:
			case MINUS:
				enterOuterAlt(_localctx, 1);
				{
				setState(588); unary_operator();
				setState(589); primary_expr();
				}
				break;
			case INTEGER_LITERAL:
			case OCTAL_LITERAL:
			case HEX_LITERAL:
			case FLOATING_PT_LITERAL:
			case FIXED_PT_LITERAL:
			case WIDE_CHARACTER_LITERAL:
			case CHARACTER_LITERAL:
			case WIDE_STRING_LITERAL:
			case STRING_LITERAL:
			case BOOLEAN_LITERAL:
			case LEFT_BRACKET:
			case DOUBLE_COLON:
			case ID:
				enterOuterAlt(_localctx, 2);
				{
				setState(591); primary_expr();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unary_operatorContext extends ParserRuleContext {
		public TerminalNode TILDE() { return getToken(IDLParser.TILDE, 0); }
		public TerminalNode MINUS() { return getToken(IDLParser.MINUS, 0); }
		public TerminalNode PLUS() { return getToken(IDLParser.PLUS, 0); }
		public Unary_operatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_operator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUnary_operator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Unary_operatorContext unary_operator() throws RecognitionException {
		Unary_operatorContext _localctx = new Unary_operatorContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_unary_operator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(594);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << TILDE) | (1L << PLUS) | (1L << MINUS))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Primary_exprContext extends ParserRuleContext {
		public Const_expContext const_exp() {
			return getRuleContext(Const_expContext.class,0);
		}
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public Primary_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitPrimary_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Primary_exprContext primary_expr() throws RecognitionException {
		Primary_exprContext _localctx = new Primary_exprContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_primary_expr);
		try {
			setState(602);
			switch (_input.LA(1)) {
			case DOUBLE_COLON:
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(596); scoped_name();
				}
				break;
			case INTEGER_LITERAL:
			case OCTAL_LITERAL:
			case HEX_LITERAL:
			case FLOATING_PT_LITERAL:
			case FIXED_PT_LITERAL:
			case WIDE_CHARACTER_LITERAL:
			case CHARACTER_LITERAL:
			case WIDE_STRING_LITERAL:
			case STRING_LITERAL:
			case BOOLEAN_LITERAL:
				enterOuterAlt(_localctx, 2);
				{
				setState(597); literal();
				}
				break;
			case LEFT_BRACKET:
				enterOuterAlt(_localctx, 3);
				{
				setState(598); match(LEFT_BRACKET);
				setState(599); const_exp();
				setState(600); match(RIGHT_BRACKET);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode FIXED_PT_LITERAL() { return getToken(IDLParser.FIXED_PT_LITERAL, 0); }
		public TerminalNode INTEGER_LITERAL() { return getToken(IDLParser.INTEGER_LITERAL, 0); }
		public TerminalNode BOOLEAN_LITERAL() { return getToken(IDLParser.BOOLEAN_LITERAL, 0); }
		public TerminalNode WIDE_STRING_LITERAL() { return getToken(IDLParser.WIDE_STRING_LITERAL, 0); }
		public TerminalNode OCTAL_LITERAL() { return getToken(IDLParser.OCTAL_LITERAL, 0); }
		public TerminalNode STRING_LITERAL() { return getToken(IDLParser.STRING_LITERAL, 0); }
		public TerminalNode WIDE_CHARACTER_LITERAL() { return getToken(IDLParser.WIDE_CHARACTER_LITERAL, 0); }
		public TerminalNode CHARACTER_LITERAL() { return getToken(IDLParser.CHARACTER_LITERAL, 0); }
		public TerminalNode FLOATING_PT_LITERAL() { return getToken(IDLParser.FLOATING_PT_LITERAL, 0); }
		public TerminalNode HEX_LITERAL() { return getToken(IDLParser.HEX_LITERAL, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(604);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTEGER_LITERAL) | (1L << OCTAL_LITERAL) | (1L << HEX_LITERAL) | (1L << FLOATING_PT_LITERAL) | (1L << FIXED_PT_LITERAL) | (1L << WIDE_CHARACTER_LITERAL) | (1L << CHARACTER_LITERAL) | (1L << WIDE_STRING_LITERAL) | (1L << STRING_LITERAL) | (1L << BOOLEAN_LITERAL))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Positive_int_constContext extends ParserRuleContext {
		public Const_expContext const_exp() {
			return getRuleContext(Const_expContext.class,0);
		}
		public Positive_int_constContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_positive_int_const; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitPositive_int_const(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Positive_int_constContext positive_int_const() throws RecognitionException {
		Positive_int_constContext _localctx = new Positive_int_constContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_positive_int_const);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(606); const_exp();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_declContext extends ParserRuleContext {
		public Struct_typeContext struct_type() {
			return getRuleContext(Struct_typeContext.class,0);
		}
		public Constr_forward_declContext constr_forward_decl() {
			return getRuleContext(Constr_forward_declContext.class,0);
		}
		public Enum_typeContext enum_type() {
			return getRuleContext(Enum_typeContext.class,0);
		}
		public TerminalNode KW_NATIVE() { return getToken(IDLParser.KW_NATIVE, 0); }
		public Type_declaratorContext type_declarator() {
			return getRuleContext(Type_declaratorContext.class,0);
		}
		public TerminalNode KW_TYPEDEF() { return getToken(IDLParser.KW_TYPEDEF, 0); }
		public Union_typeContext union_type() {
			return getRuleContext(Union_typeContext.class,0);
		}
		public Simple_declaratorContext simple_declarator() {
			return getRuleContext(Simple_declaratorContext.class,0);
		}
		public Type_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitType_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Type_declContext type_decl() throws RecognitionException {
		Type_declContext _localctx = new Type_declContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_type_decl);
		try {
			setState(616);
			switch ( getInterpreter().adaptivePredict(_input,36,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(608); match(KW_TYPEDEF);
				setState(609); type_declarator();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(610); struct_type();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(611); union_type();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(612); enum_type();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(613); match(KW_NATIVE);
				setState(614); simple_declarator();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(615); constr_forward_decl();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_declaratorContext extends ParserRuleContext {
		public DeclaratorsContext declarators() {
			return getRuleContext(DeclaratorsContext.class,0);
		}
		public Type_specContext type_spec() {
			return getRuleContext(Type_specContext.class,0);
		}
		public Type_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_declarator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitType_declarator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Type_declaratorContext type_declarator() throws RecognitionException {
		Type_declaratorContext _localctx = new Type_declaratorContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_type_declarator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(618); type_spec();
			setState(619); declarators();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_specContext extends ParserRuleContext {
		public Constr_type_specContext constr_type_spec() {
			return getRuleContext(Constr_type_specContext.class,0);
		}
		public Simple_type_specContext simple_type_spec() {
			return getRuleContext(Simple_type_specContext.class,0);
		}
		public Type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitType_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Type_specContext type_spec() throws RecognitionException {
		Type_specContext _localctx = new Type_specContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_type_spec);
		try {
			setState(623);
			switch (_input.LA(1)) {
			case DOUBLE_COLON:
			case KW_STRING:
			case KW_OCTET:
			case KW_SEQUENCE:
			case KW_WCHAR:
			case KW_SHORT:
			case KW_LONG:
			case KW_WSTRING:
			case KW_VALUEBASE:
			case KW_OBJECT:
			case KW_UNSIGNED:
			case KW_FIXED:
			case KW_ANY:
			case KW_CHAR:
			case KW_FLOAT:
			case KW_BOOLEAN:
			case KW_DOUBLE:
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(621); simple_type_spec();
				}
				break;
			case KW_STRUCT:
			case KW_ENUM:
			case KW_UNION:
				enterOuterAlt(_localctx, 2);
				{
				setState(622); constr_type_spec();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_type_specContext extends ParserRuleContext {
		public Template_type_specContext template_type_spec() {
			return getRuleContext(Template_type_specContext.class,0);
		}
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public Base_type_specContext base_type_spec() {
			return getRuleContext(Base_type_specContext.class,0);
		}
		public Simple_type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSimple_type_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Simple_type_specContext simple_type_spec() throws RecognitionException {
		Simple_type_specContext _localctx = new Simple_type_specContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_simple_type_spec);
		try {
			setState(628);
			switch (_input.LA(1)) {
			case KW_OCTET:
			case KW_WCHAR:
			case KW_SHORT:
			case KW_LONG:
			case KW_VALUEBASE:
			case KW_OBJECT:
			case KW_UNSIGNED:
			case KW_ANY:
			case KW_CHAR:
			case KW_FLOAT:
			case KW_BOOLEAN:
			case KW_DOUBLE:
				enterOuterAlt(_localctx, 1);
				{
				setState(625); base_type_spec();
				}
				break;
			case KW_STRING:
			case KW_SEQUENCE:
			case KW_WSTRING:
			case KW_FIXED:
				enterOuterAlt(_localctx, 2);
				{
				setState(626); template_type_spec();
				}
				break;
			case DOUBLE_COLON:
			case ID:
				enterOuterAlt(_localctx, 3);
				{
				setState(627); scoped_name();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Base_type_specContext extends ParserRuleContext {
		public Value_base_typeContext value_base_type() {
			return getRuleContext(Value_base_typeContext.class,0);
		}
		public Object_typeContext object_type() {
			return getRuleContext(Object_typeContext.class,0);
		}
		public Char_typeContext char_type() {
			return getRuleContext(Char_typeContext.class,0);
		}
		public Floating_pt_typeContext floating_pt_type() {
			return getRuleContext(Floating_pt_typeContext.class,0);
		}
		public Any_typeContext any_type() {
			return getRuleContext(Any_typeContext.class,0);
		}
		public Boolean_typeContext boolean_type() {
			return getRuleContext(Boolean_typeContext.class,0);
		}
		public Octet_typeContext octet_type() {
			return getRuleContext(Octet_typeContext.class,0);
		}
		public Wide_char_typeContext wide_char_type() {
			return getRuleContext(Wide_char_typeContext.class,0);
		}
		public Integer_typeContext integer_type() {
			return getRuleContext(Integer_typeContext.class,0);
		}
		public Base_type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_base_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitBase_type_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Base_type_specContext base_type_spec() throws RecognitionException {
		Base_type_specContext _localctx = new Base_type_specContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_base_type_spec);
		try {
			setState(639);
			switch ( getInterpreter().adaptivePredict(_input,39,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(630); floating_pt_type();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(631); integer_type();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(632); char_type();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(633); wide_char_type();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(634); boolean_type();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(635); octet_type();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(636); any_type();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(637); object_type();
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(638); value_base_type();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Template_type_specContext extends ParserRuleContext {
		public Fixed_pt_typeContext fixed_pt_type() {
			return getRuleContext(Fixed_pt_typeContext.class,0);
		}
		public String_typeContext string_type() {
			return getRuleContext(String_typeContext.class,0);
		}
		public Wide_string_typeContext wide_string_type() {
			return getRuleContext(Wide_string_typeContext.class,0);
		}
		public Sequence_typeContext sequence_type() {
			return getRuleContext(Sequence_typeContext.class,0);
		}
		public Template_type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_template_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitTemplate_type_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Template_type_specContext template_type_spec() throws RecognitionException {
		Template_type_specContext _localctx = new Template_type_specContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_template_type_spec);
		try {
			setState(645);
			switch (_input.LA(1)) {
			case KW_SEQUENCE:
				enterOuterAlt(_localctx, 1);
				{
				setState(641); sequence_type();
				}
				break;
			case KW_STRING:
				enterOuterAlt(_localctx, 2);
				{
				setState(642); string_type();
				}
				break;
			case KW_WSTRING:
				enterOuterAlt(_localctx, 3);
				{
				setState(643); wide_string_type();
				}
				break;
			case KW_FIXED:
				enterOuterAlt(_localctx, 4);
				{
				setState(644); fixed_pt_type();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constr_type_specContext extends ParserRuleContext {
		public Struct_typeContext struct_type() {
			return getRuleContext(Struct_typeContext.class,0);
		}
		public Enum_typeContext enum_type() {
			return getRuleContext(Enum_typeContext.class,0);
		}
		public Union_typeContext union_type() {
			return getRuleContext(Union_typeContext.class,0);
		}
		public Constr_type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constr_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitConstr_type_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Constr_type_specContext constr_type_spec() throws RecognitionException {
		Constr_type_specContext _localctx = new Constr_type_specContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_constr_type_spec);
		try {
			setState(650);
			switch (_input.LA(1)) {
			case KW_STRUCT:
				enterOuterAlt(_localctx, 1);
				{
				setState(647); struct_type();
				}
				break;
			case KW_UNION:
				enterOuterAlt(_localctx, 2);
				{
				setState(648); union_type();
				}
				break;
			case KW_ENUM:
				enterOuterAlt(_localctx, 3);
				{
				setState(649); enum_type();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclaratorsContext extends ParserRuleContext {
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public DeclaratorContext declarator(int i) {
			return getRuleContext(DeclaratorContext.class,i);
		}
		public List<DeclaratorContext> declarator() {
			return getRuleContexts(DeclaratorContext.class);
		}
		public DeclaratorsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarators; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitDeclarators(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DeclaratorsContext declarators() throws RecognitionException {
		DeclaratorsContext _localctx = new DeclaratorsContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_declarators);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(652); declarator();
			setState(657);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(653); match(COMA);
				setState(654); declarator();
				}
				}
				setState(659);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclaratorContext extends ParserRuleContext {
		public Complex_declaratorContext complex_declarator() {
			return getRuleContext(Complex_declaratorContext.class,0);
		}
		public Simple_declaratorContext simple_declarator() {
			return getRuleContext(Simple_declaratorContext.class,0);
		}
		public DeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitDeclarator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DeclaratorContext declarator() throws RecognitionException {
		DeclaratorContext _localctx = new DeclaratorContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_declarator);
		try {
			setState(662);
			switch ( getInterpreter().adaptivePredict(_input,43,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(660); simple_declarator();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(661); complex_declarator();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_declaratorContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Simple_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_declarator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSimple_declarator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Simple_declaratorContext simple_declarator() throws RecognitionException {
		Simple_declaratorContext _localctx = new Simple_declaratorContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_simple_declarator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(664); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Complex_declaratorContext extends ParserRuleContext {
		public Array_declaratorContext array_declarator() {
			return getRuleContext(Array_declaratorContext.class,0);
		}
		public Complex_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_complex_declarator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComplex_declarator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Complex_declaratorContext complex_declarator() throws RecognitionException {
		Complex_declaratorContext _localctx = new Complex_declaratorContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_complex_declarator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(666); array_declarator();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Floating_pt_typeContext extends ParserRuleContext {
		public TerminalNode KW_DOUBLE() { return getToken(IDLParser.KW_DOUBLE, 0); }
		public TerminalNode KW_FLOAT() { return getToken(IDLParser.KW_FLOAT, 0); }
		public TerminalNode KW_LONG() { return getToken(IDLParser.KW_LONG, 0); }
		public Floating_pt_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_floating_pt_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitFloating_pt_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Floating_pt_typeContext floating_pt_type() throws RecognitionException {
		Floating_pt_typeContext _localctx = new Floating_pt_typeContext(_ctx, getState());
		enterRule(_localctx, 102, RULE_floating_pt_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(672);
			switch (_input.LA(1)) {
			case KW_FLOAT:
				{
				setState(668); match(KW_FLOAT);
				}
				break;
			case KW_DOUBLE:
				{
				setState(669); match(KW_DOUBLE);
				}
				break;
			case KW_LONG:
				{
				setState(670); match(KW_LONG);
				setState(671); match(KW_DOUBLE);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Integer_typeContext extends ParserRuleContext {
		public Signed_intContext signed_int() {
			return getRuleContext(Signed_intContext.class,0);
		}
		public Unsigned_intContext unsigned_int() {
			return getRuleContext(Unsigned_intContext.class,0);
		}
		public Integer_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integer_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInteger_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Integer_typeContext integer_type() throws RecognitionException {
		Integer_typeContext _localctx = new Integer_typeContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_integer_type);
		try {
			setState(676);
			switch (_input.LA(1)) {
			case KW_SHORT:
			case KW_LONG:
				enterOuterAlt(_localctx, 1);
				{
				setState(674); signed_int();
				}
				break;
			case KW_UNSIGNED:
				enterOuterAlt(_localctx, 2);
				{
				setState(675); unsigned_int();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Signed_intContext extends ParserRuleContext {
		public Signed_longlong_intContext signed_longlong_int() {
			return getRuleContext(Signed_longlong_intContext.class,0);
		}
		public Signed_long_intContext signed_long_int() {
			return getRuleContext(Signed_long_intContext.class,0);
		}
		public Signed_short_intContext signed_short_int() {
			return getRuleContext(Signed_short_intContext.class,0);
		}
		public Signed_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signed_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSigned_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Signed_intContext signed_int() throws RecognitionException {
		Signed_intContext _localctx = new Signed_intContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_signed_int);
		try {
			setState(681);
			switch ( getInterpreter().adaptivePredict(_input,46,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(678); signed_short_int();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(679); signed_long_int();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(680); signed_longlong_int();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Signed_short_intContext extends ParserRuleContext {
		public TerminalNode KW_SHORT() { return getToken(IDLParser.KW_SHORT, 0); }
		public Signed_short_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signed_short_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSigned_short_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Signed_short_intContext signed_short_int() throws RecognitionException {
		Signed_short_intContext _localctx = new Signed_short_intContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_signed_short_int);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(683); match(KW_SHORT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Signed_long_intContext extends ParserRuleContext {
		public TerminalNode KW_LONG() { return getToken(IDLParser.KW_LONG, 0); }
		public Signed_long_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signed_long_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSigned_long_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Signed_long_intContext signed_long_int() throws RecognitionException {
		Signed_long_intContext _localctx = new Signed_long_intContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_signed_long_int);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(685); match(KW_LONG);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Signed_longlong_intContext extends ParserRuleContext {
		public List<TerminalNode> KW_LONG() { return getTokens(IDLParser.KW_LONG); }
		public TerminalNode KW_LONG(int i) {
			return getToken(IDLParser.KW_LONG, i);
		}
		public Signed_longlong_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signed_longlong_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSigned_longlong_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Signed_longlong_intContext signed_longlong_int() throws RecognitionException {
		Signed_longlong_intContext _localctx = new Signed_longlong_intContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_signed_longlong_int);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(687); match(KW_LONG);
			setState(688); match(KW_LONG);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unsigned_intContext extends ParserRuleContext {
		public Unsigned_short_intContext unsigned_short_int() {
			return getRuleContext(Unsigned_short_intContext.class,0);
		}
		public Unsigned_long_intContext unsigned_long_int() {
			return getRuleContext(Unsigned_long_intContext.class,0);
		}
		public Unsigned_longlong_intContext unsigned_longlong_int() {
			return getRuleContext(Unsigned_longlong_intContext.class,0);
		}
		public Unsigned_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsigned_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUnsigned_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Unsigned_intContext unsigned_int() throws RecognitionException {
		Unsigned_intContext _localctx = new Unsigned_intContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_unsigned_int);
		try {
			setState(693);
			switch ( getInterpreter().adaptivePredict(_input,47,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(690); unsigned_short_int();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(691); unsigned_long_int();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(692); unsigned_longlong_int();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unsigned_short_intContext extends ParserRuleContext {
		public TerminalNode KW_SHORT() { return getToken(IDLParser.KW_SHORT, 0); }
		public TerminalNode KW_UNSIGNED() { return getToken(IDLParser.KW_UNSIGNED, 0); }
		public Unsigned_short_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsigned_short_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUnsigned_short_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Unsigned_short_intContext unsigned_short_int() throws RecognitionException {
		Unsigned_short_intContext _localctx = new Unsigned_short_intContext(_ctx, getState());
		enterRule(_localctx, 116, RULE_unsigned_short_int);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(695); match(KW_UNSIGNED);
			setState(696); match(KW_SHORT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unsigned_long_intContext extends ParserRuleContext {
		public TerminalNode KW_LONG() { return getToken(IDLParser.KW_LONG, 0); }
		public TerminalNode KW_UNSIGNED() { return getToken(IDLParser.KW_UNSIGNED, 0); }
		public Unsigned_long_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsigned_long_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUnsigned_long_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Unsigned_long_intContext unsigned_long_int() throws RecognitionException {
		Unsigned_long_intContext _localctx = new Unsigned_long_intContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_unsigned_long_int);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(698); match(KW_UNSIGNED);
			setState(699); match(KW_LONG);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unsigned_longlong_intContext extends ParserRuleContext {
		public List<TerminalNode> KW_LONG() { return getTokens(IDLParser.KW_LONG); }
		public TerminalNode KW_LONG(int i) {
			return getToken(IDLParser.KW_LONG, i);
		}
		public TerminalNode KW_UNSIGNED() { return getToken(IDLParser.KW_UNSIGNED, 0); }
		public Unsigned_longlong_intContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsigned_longlong_int; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUnsigned_longlong_int(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Unsigned_longlong_intContext unsigned_longlong_int() throws RecognitionException {
		Unsigned_longlong_intContext _localctx = new Unsigned_longlong_intContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_unsigned_longlong_int);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(701); match(KW_UNSIGNED);
			setState(702); match(KW_LONG);
			setState(703); match(KW_LONG);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Char_typeContext extends ParserRuleContext {
		public TerminalNode KW_CHAR() { return getToken(IDLParser.KW_CHAR, 0); }
		public Char_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_char_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitChar_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Char_typeContext char_type() throws RecognitionException {
		Char_typeContext _localctx = new Char_typeContext(_ctx, getState());
		enterRule(_localctx, 122, RULE_char_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(705); match(KW_CHAR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Wide_char_typeContext extends ParserRuleContext {
		public TerminalNode KW_WCHAR() { return getToken(IDLParser.KW_WCHAR, 0); }
		public Wide_char_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_wide_char_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitWide_char_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Wide_char_typeContext wide_char_type() throws RecognitionException {
		Wide_char_typeContext _localctx = new Wide_char_typeContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_wide_char_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(707); match(KW_WCHAR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Boolean_typeContext extends ParserRuleContext {
		public TerminalNode KW_BOOLEAN() { return getToken(IDLParser.KW_BOOLEAN, 0); }
		public Boolean_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolean_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitBoolean_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Boolean_typeContext boolean_type() throws RecognitionException {
		Boolean_typeContext _localctx = new Boolean_typeContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_boolean_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(709); match(KW_BOOLEAN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Octet_typeContext extends ParserRuleContext {
		public TerminalNode KW_OCTET() { return getToken(IDLParser.KW_OCTET, 0); }
		public Octet_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_octet_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitOctet_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Octet_typeContext octet_type() throws RecognitionException {
		Octet_typeContext _localctx = new Octet_typeContext(_ctx, getState());
		enterRule(_localctx, 128, RULE_octet_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(711); match(KW_OCTET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Any_typeContext extends ParserRuleContext {
		public TerminalNode KW_ANY() { return getToken(IDLParser.KW_ANY, 0); }
		public Any_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_any_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitAny_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Any_typeContext any_type() throws RecognitionException {
		Any_typeContext _localctx = new Any_typeContext(_ctx, getState());
		enterRule(_localctx, 130, RULE_any_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(713); match(KW_ANY);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Object_typeContext extends ParserRuleContext {
		public TerminalNode KW_OBJECT() { return getToken(IDLParser.KW_OBJECT, 0); }
		public Object_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitObject_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Object_typeContext object_type() throws RecognitionException {
		Object_typeContext _localctx = new Object_typeContext(_ctx, getState());
		enterRule(_localctx, 132, RULE_object_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(715); match(KW_OBJECT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Struct_typeContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public Member_listContext member_list() {
			return getRuleContext(Member_listContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_STRUCT() { return getToken(IDLParser.KW_STRUCT, 0); }
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Struct_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_struct_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitStruct_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Struct_typeContext struct_type() throws RecognitionException {
		Struct_typeContext _localctx = new Struct_typeContext(_ctx, getState());
		enterRule(_localctx, 134, RULE_struct_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(717); match(KW_STRUCT);
			setState(718); match(ID);
			setState(719); match(LEFT_BRACE);
			setState(720); member_list();
			setState(721); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Member_listContext extends ParserRuleContext {
		public List<MemberContext> member() {
			return getRuleContexts(MemberContext.class);
		}
		public MemberContext member(int i) {
			return getRuleContext(MemberContext.class,i);
		}
		public Member_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member_list; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitMember_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Member_listContext member_list() throws RecognitionException {
		Member_listContext _localctx = new Member_listContext(_ctx, getState());
		enterRule(_localctx, 136, RULE_member_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(724); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(723); member();
				}
				}
				setState(726); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_OCTET) | (1L << KW_SEQUENCE) | (1L << KW_STRUCT) | (1L << KW_WCHAR) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_FIXED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (ID - 64)))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MemberContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public DeclaratorsContext declarators() {
			return getRuleContext(DeclaratorsContext.class,0);
		}
		public Type_specContext type_spec() {
			return getRuleContext(Type_specContext.class,0);
		}
		public MemberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitMember(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MemberContext member() throws RecognitionException {
		MemberContext _localctx = new MemberContext(_ctx, getState());
		enterRule(_localctx, 138, RULE_member);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(728); type_spec();
			setState(729); declarators();
			setState(730); match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Union_typeContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public TerminalNode KW_SWITCH() { return getToken(IDLParser.KW_SWITCH, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Switch_bodyContext switch_body() {
			return getRuleContext(Switch_bodyContext.class,0);
		}
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public Switch_type_specContext switch_type_spec() {
			return getRuleContext(Switch_type_specContext.class,0);
		}
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public TerminalNode KW_UNION() { return getToken(IDLParser.KW_UNION, 0); }
		public Union_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_union_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUnion_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Union_typeContext union_type() throws RecognitionException {
		Union_typeContext _localctx = new Union_typeContext(_ctx, getState());
		enterRule(_localctx, 140, RULE_union_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(732); match(KW_UNION);
			setState(733); match(ID);
			setState(734); match(KW_SWITCH);
			setState(735); match(LEFT_BRACKET);
			setState(736); switch_type_spec();
			setState(737); match(RIGHT_BRACKET);
			setState(738); match(LEFT_BRACE);
			setState(739); switch_body();
			setState(740); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Switch_type_specContext extends ParserRuleContext {
		public Char_typeContext char_type() {
			return getRuleContext(Char_typeContext.class,0);
		}
		public Enum_typeContext enum_type() {
			return getRuleContext(Enum_typeContext.class,0);
		}
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public Boolean_typeContext boolean_type() {
			return getRuleContext(Boolean_typeContext.class,0);
		}
		public Integer_typeContext integer_type() {
			return getRuleContext(Integer_typeContext.class,0);
		}
		public Switch_type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switch_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSwitch_type_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Switch_type_specContext switch_type_spec() throws RecognitionException {
		Switch_type_specContext _localctx = new Switch_type_specContext(_ctx, getState());
		enterRule(_localctx, 142, RULE_switch_type_spec);
		try {
			setState(747);
			switch (_input.LA(1)) {
			case KW_SHORT:
			case KW_LONG:
			case KW_UNSIGNED:
				enterOuterAlt(_localctx, 1);
				{
				setState(742); integer_type();
				}
				break;
			case KW_CHAR:
				enterOuterAlt(_localctx, 2);
				{
				setState(743); char_type();
				}
				break;
			case KW_BOOLEAN:
				enterOuterAlt(_localctx, 3);
				{
				setState(744); boolean_type();
				}
				break;
			case KW_ENUM:
				enterOuterAlt(_localctx, 4);
				{
				setState(745); enum_type();
				}
				break;
			case DOUBLE_COLON:
			case ID:
				enterOuterAlt(_localctx, 5);
				{
				setState(746); scoped_name();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Switch_bodyContext extends ParserRuleContext {
		public List<Case_stmtContext> case_stmt() {
			return getRuleContexts(Case_stmtContext.class);
		}
		public Case_stmtContext case_stmt(int i) {
			return getRuleContext(Case_stmtContext.class,i);
		}
		public Switch_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switch_body; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSwitch_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Switch_bodyContext switch_body() throws RecognitionException {
		Switch_bodyContext _localctx = new Switch_bodyContext(_ctx, getState());
		enterRule(_localctx, 144, RULE_switch_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(750); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(749); case_stmt();
				}
				}
				setState(752); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==KW_DEFAULT || _la==KW_CASE );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Case_stmtContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public Element_specContext element_spec() {
			return getRuleContext(Element_specContext.class,0);
		}
		public Case_labelContext case_label(int i) {
			return getRuleContext(Case_labelContext.class,i);
		}
		public List<Case_labelContext> case_label() {
			return getRuleContexts(Case_labelContext.class);
		}
		public Case_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_stmt; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitCase_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Case_stmtContext case_stmt() throws RecognitionException {
		Case_stmtContext _localctx = new Case_stmtContext(_ctx, getState());
		enterRule(_localctx, 146, RULE_case_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(755); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(754); case_label();
				}
				}
				setState(757); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==KW_DEFAULT || _la==KW_CASE );
			setState(759); element_spec();
			setState(760); match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Case_labelContext extends ParserRuleContext {
		public TerminalNode KW_CASE() { return getToken(IDLParser.KW_CASE, 0); }
		public Const_expContext const_exp() {
			return getRuleContext(Const_expContext.class,0);
		}
		public TerminalNode KW_DEFAULT() { return getToken(IDLParser.KW_DEFAULT, 0); }
		public TerminalNode COLON() { return getToken(IDLParser.COLON, 0); }
		public Case_labelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_label; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitCase_label(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Case_labelContext case_label() throws RecognitionException {
		Case_labelContext _localctx = new Case_labelContext(_ctx, getState());
		enterRule(_localctx, 148, RULE_case_label);
		try {
			setState(768);
			switch (_input.LA(1)) {
			case KW_CASE:
				enterOuterAlt(_localctx, 1);
				{
				setState(762); match(KW_CASE);
				setState(763); const_exp();
				setState(764); match(COLON);
				}
				break;
			case KW_DEFAULT:
				enterOuterAlt(_localctx, 2);
				{
				setState(766); match(KW_DEFAULT);
				setState(767); match(COLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Element_specContext extends ParserRuleContext {
		public Type_specContext type_spec() {
			return getRuleContext(Type_specContext.class,0);
		}
		public DeclaratorContext declarator() {
			return getRuleContext(DeclaratorContext.class,0);
		}
		public Element_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_element_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitElement_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Element_specContext element_spec() throws RecognitionException {
		Element_specContext _localctx = new Element_specContext(_ctx, getState());
		enterRule(_localctx, 150, RULE_element_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(770); type_spec();
			setState(771); declarator();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Enum_typeContext extends ParserRuleContext {
		public EnumeratorContext enumerator(int i) {
			return getRuleContext(EnumeratorContext.class,i);
		}
		public List<EnumeratorContext> enumerator() {
			return getRuleContexts(EnumeratorContext.class);
		}
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public TerminalNode KW_ENUM() { return getToken(IDLParser.KW_ENUM, 0); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public Enum_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enum_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEnum_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Enum_typeContext enum_type() throws RecognitionException {
		Enum_typeContext _localctx = new Enum_typeContext(_ctx, getState());
		enterRule(_localctx, 152, RULE_enum_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(773); match(KW_ENUM);
			setState(774); match(ID);
			setState(775); match(LEFT_BRACE);
			setState(776); enumerator();
			setState(781);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(777); match(COMA);
				setState(778); enumerator();
				}
				}
				setState(783);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(784); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EnumeratorContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public EnumeratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumerator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEnumerator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final EnumeratorContext enumerator() throws RecognitionException {
		EnumeratorContext _localctx = new EnumeratorContext(_ctx, getState());
		enterRule(_localctx, 154, RULE_enumerator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(786); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Sequence_typeContext extends ParserRuleContext {
		public Positive_int_constContext positive_int_const() {
			return getRuleContext(Positive_int_constContext.class,0);
		}
		public TerminalNode COMA() { return getToken(IDLParser.COMA, 0); }
		public TerminalNode RIGHT_ANG_BRACKET() { return getToken(IDLParser.RIGHT_ANG_BRACKET, 0); }
		public Simple_type_specContext simple_type_spec() {
			return getRuleContext(Simple_type_specContext.class,0);
		}
		public TerminalNode KW_SEQUENCE() { return getToken(IDLParser.KW_SEQUENCE, 0); }
		public TerminalNode LEFT_ANG_BRACKET() { return getToken(IDLParser.LEFT_ANG_BRACKET, 0); }
		public Sequence_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sequence_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSequence_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Sequence_typeContext sequence_type() throws RecognitionException {
		Sequence_typeContext _localctx = new Sequence_typeContext(_ctx, getState());
		enterRule(_localctx, 156, RULE_sequence_type);
		try {
			setState(800);
			switch ( getInterpreter().adaptivePredict(_input,54,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(788); match(KW_SEQUENCE);
				setState(789); match(LEFT_ANG_BRACKET);
				setState(790); simple_type_spec();
				setState(791); match(COMA);
				setState(792); positive_int_const();
				setState(793); match(RIGHT_ANG_BRACKET);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(795); match(KW_SEQUENCE);
				setState(796); match(LEFT_ANG_BRACKET);
				setState(797); simple_type_spec();
				setState(798); match(RIGHT_ANG_BRACKET);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class String_typeContext extends ParserRuleContext {
		public Positive_int_constContext positive_int_const() {
			return getRuleContext(Positive_int_constContext.class,0);
		}
		public TerminalNode RIGHT_ANG_BRACKET() { return getToken(IDLParser.RIGHT_ANG_BRACKET, 0); }
		public TerminalNode KW_STRING() { return getToken(IDLParser.KW_STRING, 0); }
		public TerminalNode LEFT_ANG_BRACKET() { return getToken(IDLParser.LEFT_ANG_BRACKET, 0); }
		public String_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitString_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final String_typeContext string_type() throws RecognitionException {
		String_typeContext _localctx = new String_typeContext(_ctx, getState());
		enterRule(_localctx, 158, RULE_string_type);
		try {
			setState(808);
			switch ( getInterpreter().adaptivePredict(_input,55,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(802); match(KW_STRING);
				setState(803); match(LEFT_ANG_BRACKET);
				setState(804); positive_int_const();
				setState(805); match(RIGHT_ANG_BRACKET);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(807); match(KW_STRING);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Wide_string_typeContext extends ParserRuleContext {
		public Positive_int_constContext positive_int_const() {
			return getRuleContext(Positive_int_constContext.class,0);
		}
		public TerminalNode KW_WSTRING() { return getToken(IDLParser.KW_WSTRING, 0); }
		public TerminalNode RIGHT_ANG_BRACKET() { return getToken(IDLParser.RIGHT_ANG_BRACKET, 0); }
		public TerminalNode LEFT_ANG_BRACKET() { return getToken(IDLParser.LEFT_ANG_BRACKET, 0); }
		public Wide_string_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_wide_string_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitWide_string_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Wide_string_typeContext wide_string_type() throws RecognitionException {
		Wide_string_typeContext _localctx = new Wide_string_typeContext(_ctx, getState());
		enterRule(_localctx, 160, RULE_wide_string_type);
		try {
			setState(816);
			switch ( getInterpreter().adaptivePredict(_input,56,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(810); match(KW_WSTRING);
				setState(811); match(LEFT_ANG_BRACKET);
				setState(812); positive_int_const();
				setState(813); match(RIGHT_ANG_BRACKET);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(815); match(KW_WSTRING);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Array_declaratorContext extends ParserRuleContext {
		public List<Fixed_array_sizeContext> fixed_array_size() {
			return getRuleContexts(Fixed_array_sizeContext.class);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Fixed_array_sizeContext fixed_array_size(int i) {
			return getRuleContext(Fixed_array_sizeContext.class,i);
		}
		public Array_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_declarator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitArray_declarator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Array_declaratorContext array_declarator() throws RecognitionException {
		Array_declaratorContext _localctx = new Array_declaratorContext(_ctx, getState());
		enterRule(_localctx, 162, RULE_array_declarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(818); match(ID);
			setState(820); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(819); fixed_array_size();
				}
				}
				setState(822); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==LEFT_SQUARE_BRACKET );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Fixed_array_sizeContext extends ParserRuleContext {
		public Positive_int_constContext positive_int_const() {
			return getRuleContext(Positive_int_constContext.class,0);
		}
		public TerminalNode LEFT_SQUARE_BRACKET() { return getToken(IDLParser.LEFT_SQUARE_BRACKET, 0); }
		public TerminalNode RIGHT_SQUARE_BRACKET() { return getToken(IDLParser.RIGHT_SQUARE_BRACKET, 0); }
		public Fixed_array_sizeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fixed_array_size; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitFixed_array_size(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Fixed_array_sizeContext fixed_array_size() throws RecognitionException {
		Fixed_array_sizeContext _localctx = new Fixed_array_sizeContext(_ctx, getState());
		enterRule(_localctx, 164, RULE_fixed_array_size);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(824); match(LEFT_SQUARE_BRACKET);
			setState(825); positive_int_const();
			setState(826); match(RIGHT_SQUARE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Attr_declContext extends ParserRuleContext {
		public Readonly_attr_specContext readonly_attr_spec() {
			return getRuleContext(Readonly_attr_specContext.class,0);
		}
		public Attr_specContext attr_spec() {
			return getRuleContext(Attr_specContext.class,0);
		}
		public Attr_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_attr_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitAttr_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Attr_declContext attr_decl() throws RecognitionException {
		Attr_declContext _localctx = new Attr_declContext(_ctx, getState());
		enterRule(_localctx, 166, RULE_attr_decl);
		try {
			setState(830);
			switch (_input.LA(1)) {
			case KW_READONLY:
				enterOuterAlt(_localctx, 1);
				{
				setState(828); readonly_attr_spec();
				}
				break;
			case KW_ATTRIBUTE:
				enterOuterAlt(_localctx, 2);
				{
				setState(829); attr_spec();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Except_declContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public List<MemberContext> member() {
			return getRuleContexts(MemberContext.class);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public MemberContext member(int i) {
			return getRuleContext(MemberContext.class,i);
		}
		public TerminalNode KW_EXCEPTION() { return getToken(IDLParser.KW_EXCEPTION, 0); }
		public Except_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_except_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitExcept_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Except_declContext except_decl() throws RecognitionException {
		Except_declContext _localctx = new Except_declContext(_ctx, getState());
		enterRule(_localctx, 168, RULE_except_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(832); match(KW_EXCEPTION);
			setState(833); match(ID);
			setState(834); match(LEFT_BRACE);
			setState(838);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_OCTET) | (1L << KW_SEQUENCE) | (1L << KW_STRUCT) | (1L << KW_WCHAR) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_FIXED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (ID - 64)))) != 0)) {
				{
				{
				setState(835); member();
				}
				}
				setState(840);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(841); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Op_declContext extends ParserRuleContext {
		public Context_exprContext context_expr() {
			return getRuleContext(Context_exprContext.class,0);
		}
		public Op_attributeContext op_attribute() {
			return getRuleContext(Op_attributeContext.class,0);
		}
		public Raises_exprContext raises_expr() {
			return getRuleContext(Raises_exprContext.class,0);
		}
		public Op_type_specContext op_type_spec() {
			return getRuleContext(Op_type_specContext.class,0);
		}
		public Parameter_declsContext parameter_decls() {
			return getRuleContext(Parameter_declsContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Op_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_op_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitOp_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Op_declContext op_decl() throws RecognitionException {
		Op_declContext _localctx = new Op_declContext(_ctx, getState());
		enterRule(_localctx, 170, RULE_op_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(844);
			_la = _input.LA(1);
			if (_la==KW_ONEWAY) {
				{
				setState(843); op_attribute();
				}
			}

			setState(846); op_type_spec();
			setState(847); match(ID);
			setState(848); parameter_decls();
			setState(850);
			_la = _input.LA(1);
			if (_la==KW_RAISES) {
				{
				setState(849); raises_expr();
				}
			}

			setState(853);
			_la = _input.LA(1);
			if (_la==KW_CONTEXT) {
				{
				setState(852); context_expr();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Op_attributeContext extends ParserRuleContext {
		public TerminalNode KW_ONEWAY() { return getToken(IDLParser.KW_ONEWAY, 0); }
		public Op_attributeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_op_attribute; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitOp_attribute(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Op_attributeContext op_attribute() throws RecognitionException {
		Op_attributeContext _localctx = new Op_attributeContext(_ctx, getState());
		enterRule(_localctx, 172, RULE_op_attribute);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(855); match(KW_ONEWAY);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Op_type_specContext extends ParserRuleContext {
		public TerminalNode KW_VOID() { return getToken(IDLParser.KW_VOID, 0); }
		public Param_type_specContext param_type_spec() {
			return getRuleContext(Param_type_specContext.class,0);
		}
		public Op_type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_op_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitOp_type_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Op_type_specContext op_type_spec() throws RecognitionException {
		Op_type_specContext _localctx = new Op_type_specContext(_ctx, getState());
		enterRule(_localctx, 174, RULE_op_type_spec);
		try {
			setState(859);
			switch (_input.LA(1)) {
			case DOUBLE_COLON:
			case KW_STRING:
			case KW_OCTET:
			case KW_WCHAR:
			case KW_SHORT:
			case KW_LONG:
			case KW_WSTRING:
			case KW_VALUEBASE:
			case KW_OBJECT:
			case KW_UNSIGNED:
			case KW_ANY:
			case KW_CHAR:
			case KW_FLOAT:
			case KW_BOOLEAN:
			case KW_DOUBLE:
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(857); param_type_spec();
				}
				break;
			case KW_VOID:
				enterOuterAlt(_localctx, 2);
				{
				setState(858); match(KW_VOID);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Parameter_declsContext extends ParserRuleContext {
		public Param_declContext param_decl(int i) {
			return getRuleContext(Param_declContext.class,i);
		}
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public List<Param_declContext> param_decl() {
			return getRuleContexts(Param_declContext.class);
		}
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public Parameter_declsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_decls; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitParameter_decls(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Parameter_declsContext parameter_decls() throws RecognitionException {
		Parameter_declsContext _localctx = new Parameter_declsContext(_ctx, getState());
		enterRule(_localctx, 176, RULE_parameter_decls);
		int _la;
		try {
			setState(874);
			switch ( getInterpreter().adaptivePredict(_input,65,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(861); match(LEFT_BRACKET);
				setState(862); param_decl();
				setState(867);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMA) {
					{
					{
					setState(863); match(COMA);
					setState(864); param_decl();
					}
					}
					setState(869);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(870); match(RIGHT_BRACKET);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(872); match(LEFT_BRACKET);
				setState(873); match(RIGHT_BRACKET);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Param_declContext extends ParserRuleContext {
		public Param_attributeContext param_attribute() {
			return getRuleContext(Param_attributeContext.class,0);
		}
		public Param_type_specContext param_type_spec() {
			return getRuleContext(Param_type_specContext.class,0);
		}
		public Simple_declaratorContext simple_declarator() {
			return getRuleContext(Simple_declaratorContext.class,0);
		}
		public Param_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_param_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitParam_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Param_declContext param_decl() throws RecognitionException {
		Param_declContext _localctx = new Param_declContext(_ctx, getState());
		enterRule(_localctx, 178, RULE_param_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(876); param_attribute();
			setState(877); param_type_spec();
			setState(878); simple_declarator();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Param_attributeContext extends ParserRuleContext {
		public TerminalNode KW_OUT() { return getToken(IDLParser.KW_OUT, 0); }
		public TerminalNode KW_IN() { return getToken(IDLParser.KW_IN, 0); }
		public TerminalNode KW_INOUT() { return getToken(IDLParser.KW_INOUT, 0); }
		public Param_attributeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_param_attribute; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitParam_attribute(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Param_attributeContext param_attribute() throws RecognitionException {
		Param_attributeContext _localctx = new Param_attributeContext(_ctx, getState());
		enterRule(_localctx, 180, RULE_param_attribute);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(880);
			_la = _input.LA(1);
			if ( !(((((_la - 38)) & ~0x3f) == 0 && ((1L << (_la - 38)) & ((1L << (KW_OUT - 38)) | (1L << (KW_IN - 38)) | (1L << (KW_INOUT - 38)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Raises_exprContext extends ParserRuleContext {
		public List<Scoped_nameContext> scoped_name() {
			return getRuleContexts(Scoped_nameContext.class);
		}
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public Scoped_nameContext scoped_name(int i) {
			return getRuleContext(Scoped_nameContext.class,i);
		}
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public TerminalNode KW_RAISES() { return getToken(IDLParser.KW_RAISES, 0); }
		public Raises_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_raises_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitRaises_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Raises_exprContext raises_expr() throws RecognitionException {
		Raises_exprContext _localctx = new Raises_exprContext(_ctx, getState());
		enterRule(_localctx, 182, RULE_raises_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(882); match(KW_RAISES);
			setState(883); match(LEFT_BRACKET);
			setState(884); scoped_name();
			setState(889);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(885); match(COMA);
				setState(886); scoped_name();
				}
				}
				setState(891);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(892); match(RIGHT_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Context_exprContext extends ParserRuleContext {
		public TerminalNode STRING_LITERAL(int i) {
			return getToken(IDLParser.STRING_LITERAL, i);
		}
		public List<TerminalNode> STRING_LITERAL() { return getTokens(IDLParser.STRING_LITERAL); }
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public TerminalNode KW_CONTEXT() { return getToken(IDLParser.KW_CONTEXT, 0); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public Context_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_context_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitContext_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Context_exprContext context_expr() throws RecognitionException {
		Context_exprContext _localctx = new Context_exprContext(_ctx, getState());
		enterRule(_localctx, 184, RULE_context_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(894); match(KW_CONTEXT);
			setState(895); match(LEFT_BRACKET);
			setState(896); match(STRING_LITERAL);
			setState(901);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(897); match(COMA);
				setState(898); match(STRING_LITERAL);
				}
				}
				setState(903);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(904); match(RIGHT_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Param_type_specContext extends ParserRuleContext {
		public String_typeContext string_type() {
			return getRuleContext(String_typeContext.class,0);
		}
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public Wide_string_typeContext wide_string_type() {
			return getRuleContext(Wide_string_typeContext.class,0);
		}
		public Base_type_specContext base_type_spec() {
			return getRuleContext(Base_type_specContext.class,0);
		}
		public Param_type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_param_type_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitParam_type_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Param_type_specContext param_type_spec() throws RecognitionException {
		Param_type_specContext _localctx = new Param_type_specContext(_ctx, getState());
		enterRule(_localctx, 186, RULE_param_type_spec);
		try {
			setState(910);
			switch (_input.LA(1)) {
			case KW_OCTET:
			case KW_WCHAR:
			case KW_SHORT:
			case KW_LONG:
			case KW_VALUEBASE:
			case KW_OBJECT:
			case KW_UNSIGNED:
			case KW_ANY:
			case KW_CHAR:
			case KW_FLOAT:
			case KW_BOOLEAN:
			case KW_DOUBLE:
				enterOuterAlt(_localctx, 1);
				{
				setState(906); base_type_spec();
				}
				break;
			case KW_STRING:
				enterOuterAlt(_localctx, 2);
				{
				setState(907); string_type();
				}
				break;
			case KW_WSTRING:
				enterOuterAlt(_localctx, 3);
				{
				setState(908); wide_string_type();
				}
				break;
			case DOUBLE_COLON:
			case ID:
				enterOuterAlt(_localctx, 4);
				{
				setState(909); scoped_name();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Fixed_pt_typeContext extends ParserRuleContext {
		public List<Positive_int_constContext> positive_int_const() {
			return getRuleContexts(Positive_int_constContext.class);
		}
		public Positive_int_constContext positive_int_const(int i) {
			return getRuleContext(Positive_int_constContext.class,i);
		}
		public TerminalNode KW_FIXED() { return getToken(IDLParser.KW_FIXED, 0); }
		public TerminalNode COMA() { return getToken(IDLParser.COMA, 0); }
		public TerminalNode RIGHT_ANG_BRACKET() { return getToken(IDLParser.RIGHT_ANG_BRACKET, 0); }
		public TerminalNode LEFT_ANG_BRACKET() { return getToken(IDLParser.LEFT_ANG_BRACKET, 0); }
		public Fixed_pt_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fixed_pt_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitFixed_pt_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Fixed_pt_typeContext fixed_pt_type() throws RecognitionException {
		Fixed_pt_typeContext _localctx = new Fixed_pt_typeContext(_ctx, getState());
		enterRule(_localctx, 188, RULE_fixed_pt_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(912); match(KW_FIXED);
			setState(913); match(LEFT_ANG_BRACKET);
			setState(914); positive_int_const();
			setState(915); match(COMA);
			setState(916); positive_int_const();
			setState(917); match(RIGHT_ANG_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Fixed_pt_const_typeContext extends ParserRuleContext {
		public TerminalNode KW_FIXED() { return getToken(IDLParser.KW_FIXED, 0); }
		public Fixed_pt_const_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fixed_pt_const_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitFixed_pt_const_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Fixed_pt_const_typeContext fixed_pt_const_type() throws RecognitionException {
		Fixed_pt_const_typeContext _localctx = new Fixed_pt_const_typeContext(_ctx, getState());
		enterRule(_localctx, 190, RULE_fixed_pt_const_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(919); match(KW_FIXED);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Value_base_typeContext extends ParserRuleContext {
		public TerminalNode KW_VALUEBASE() { return getToken(IDLParser.KW_VALUEBASE, 0); }
		public Value_base_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_base_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitValue_base_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Value_base_typeContext value_base_type() throws RecognitionException {
		Value_base_typeContext _localctx = new Value_base_typeContext(_ctx, getState());
		enterRule(_localctx, 192, RULE_value_base_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(921); match(KW_VALUEBASE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constr_forward_declContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_STRUCT() { return getToken(IDLParser.KW_STRUCT, 0); }
		public TerminalNode KW_UNION() { return getToken(IDLParser.KW_UNION, 0); }
		public Constr_forward_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constr_forward_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitConstr_forward_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Constr_forward_declContext constr_forward_decl() throws RecognitionException {
		Constr_forward_declContext _localctx = new Constr_forward_declContext(_ctx, getState());
		enterRule(_localctx, 194, RULE_constr_forward_decl);
		try {
			setState(927);
			switch (_input.LA(1)) {
			case KW_STRUCT:
				enterOuterAlt(_localctx, 1);
				{
				setState(923); match(KW_STRUCT);
				setState(924); match(ID);
				}
				break;
			case KW_UNION:
				enterOuterAlt(_localctx, 2);
				{
				setState(925); match(KW_UNION);
				setState(926); match(ID);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Import_declContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public Imported_scopeContext imported_scope() {
			return getRuleContext(Imported_scopeContext.class,0);
		}
		public TerminalNode KW_IMPORT() { return getToken(IDLParser.KW_IMPORT, 0); }
		public Import_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_import_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitImport_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Import_declContext import_decl() throws RecognitionException {
		Import_declContext _localctx = new Import_declContext(_ctx, getState());
		enterRule(_localctx, 196, RULE_import_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(929); match(KW_IMPORT);
			setState(930); imported_scope();
			setState(931); match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Imported_scopeContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode STRING_LITERAL() { return getToken(IDLParser.STRING_LITERAL, 0); }
		public Imported_scopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_imported_scope; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitImported_scope(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Imported_scopeContext imported_scope() throws RecognitionException {
		Imported_scopeContext _localctx = new Imported_scopeContext(_ctx, getState());
		enterRule(_localctx, 198, RULE_imported_scope);
		try {
			setState(935);
			switch (_input.LA(1)) {
			case DOUBLE_COLON:
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(933); scoped_name();
				}
				break;
			case STRING_LITERAL:
				enterOuterAlt(_localctx, 2);
				{
				setState(934); match(STRING_LITERAL);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_id_declContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode STRING_LITERAL() { return getToken(IDLParser.STRING_LITERAL, 0); }
		public TerminalNode KW_TYPEID() { return getToken(IDLParser.KW_TYPEID, 0); }
		public Type_id_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_id_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitType_id_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Type_id_declContext type_id_decl() throws RecognitionException {
		Type_id_declContext _localctx = new Type_id_declContext(_ctx, getState());
		enterRule(_localctx, 200, RULE_type_id_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(937); match(KW_TYPEID);
			setState(938); scoped_name();
			setState(939); match(STRING_LITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_prefix_declContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode STRING_LITERAL() { return getToken(IDLParser.STRING_LITERAL, 0); }
		public TerminalNode KW_TYPEPREFIX() { return getToken(IDLParser.KW_TYPEPREFIX, 0); }
		public Type_prefix_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_prefix_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitType_prefix_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Type_prefix_declContext type_prefix_decl() throws RecognitionException {
		Type_prefix_declContext _localctx = new Type_prefix_declContext(_ctx, getState());
		enterRule(_localctx, 202, RULE_type_prefix_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(941); match(KW_TYPEPREFIX);
			setState(942); scoped_name();
			setState(943); match(STRING_LITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Readonly_attr_specContext extends ParserRuleContext {
		public TerminalNode KW_ATTRIBUTE() { return getToken(IDLParser.KW_ATTRIBUTE, 0); }
		public Readonly_attr_declaratorContext readonly_attr_declarator() {
			return getRuleContext(Readonly_attr_declaratorContext.class,0);
		}
		public Param_type_specContext param_type_spec() {
			return getRuleContext(Param_type_specContext.class,0);
		}
		public TerminalNode KW_READONLY() { return getToken(IDLParser.KW_READONLY, 0); }
		public Readonly_attr_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_readonly_attr_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitReadonly_attr_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Readonly_attr_specContext readonly_attr_spec() throws RecognitionException {
		Readonly_attr_specContext _localctx = new Readonly_attr_specContext(_ctx, getState());
		enterRule(_localctx, 204, RULE_readonly_attr_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(945); match(KW_READONLY);
			setState(946); match(KW_ATTRIBUTE);
			setState(947); param_type_spec();
			setState(948); readonly_attr_declarator();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Readonly_attr_declaratorContext extends ParserRuleContext {
		public Raises_exprContext raises_expr() {
			return getRuleContext(Raises_exprContext.class,0);
		}
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public Simple_declaratorContext simple_declarator(int i) {
			return getRuleContext(Simple_declaratorContext.class,i);
		}
		public List<Simple_declaratorContext> simple_declarator() {
			return getRuleContexts(Simple_declaratorContext.class);
		}
		public Readonly_attr_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_readonly_attr_declarator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitReadonly_attr_declarator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Readonly_attr_declaratorContext readonly_attr_declarator() throws RecognitionException {
		Readonly_attr_declaratorContext _localctx = new Readonly_attr_declaratorContext(_ctx, getState());
		enterRule(_localctx, 206, RULE_readonly_attr_declarator);
		int _la;
		try {
			setState(961);
			switch ( getInterpreter().adaptivePredict(_input,72,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(950); simple_declarator();
				setState(951); raises_expr();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(953); simple_declarator();
				setState(958);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMA) {
					{
					{
					setState(954); match(COMA);
					setState(955); simple_declarator();
					}
					}
					setState(960);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Attr_specContext extends ParserRuleContext {
		public TerminalNode KW_ATTRIBUTE() { return getToken(IDLParser.KW_ATTRIBUTE, 0); }
		public Attr_declaratorContext attr_declarator() {
			return getRuleContext(Attr_declaratorContext.class,0);
		}
		public Param_type_specContext param_type_spec() {
			return getRuleContext(Param_type_specContext.class,0);
		}
		public Attr_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_attr_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitAttr_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Attr_specContext attr_spec() throws RecognitionException {
		Attr_specContext _localctx = new Attr_specContext(_ctx, getState());
		enterRule(_localctx, 208, RULE_attr_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(963); match(KW_ATTRIBUTE);
			setState(964); param_type_spec();
			setState(965); attr_declarator();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Attr_declaratorContext extends ParserRuleContext {
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public Attr_raises_exprContext attr_raises_expr() {
			return getRuleContext(Attr_raises_exprContext.class,0);
		}
		public Simple_declaratorContext simple_declarator(int i) {
			return getRuleContext(Simple_declaratorContext.class,i);
		}
		public List<Simple_declaratorContext> simple_declarator() {
			return getRuleContexts(Simple_declaratorContext.class);
		}
		public Attr_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_attr_declarator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitAttr_declarator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Attr_declaratorContext attr_declarator() throws RecognitionException {
		Attr_declaratorContext _localctx = new Attr_declaratorContext(_ctx, getState());
		enterRule(_localctx, 210, RULE_attr_declarator);
		int _la;
		try {
			setState(978);
			switch ( getInterpreter().adaptivePredict(_input,74,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(967); simple_declarator();
				setState(968); attr_raises_expr();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(970); simple_declarator();
				setState(975);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMA) {
					{
					{
					setState(971); match(COMA);
					setState(972); simple_declarator();
					}
					}
					setState(977);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Attr_raises_exprContext extends ParserRuleContext {
		public Get_excep_exprContext get_excep_expr() {
			return getRuleContext(Get_excep_exprContext.class,0);
		}
		public Set_excep_exprContext set_excep_expr() {
			return getRuleContext(Set_excep_exprContext.class,0);
		}
		public Attr_raises_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_attr_raises_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitAttr_raises_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Attr_raises_exprContext attr_raises_expr() throws RecognitionException {
		Attr_raises_exprContext _localctx = new Attr_raises_exprContext(_ctx, getState());
		enterRule(_localctx, 212, RULE_attr_raises_expr);
		int _la;
		try {
			setState(985);
			switch (_input.LA(1)) {
			case KW_GETRAISES:
				enterOuterAlt(_localctx, 1);
				{
				setState(980); get_excep_expr();
				setState(982);
				_la = _input.LA(1);
				if (_la==KW_SETRAISES) {
					{
					setState(981); set_excep_expr();
					}
				}

				}
				break;
			case KW_SETRAISES:
				enterOuterAlt(_localctx, 2);
				{
				setState(984); set_excep_expr();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Get_excep_exprContext extends ParserRuleContext {
		public Exception_listContext exception_list() {
			return getRuleContext(Exception_listContext.class,0);
		}
		public TerminalNode KW_GETRAISES() { return getToken(IDLParser.KW_GETRAISES, 0); }
		public Get_excep_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_get_excep_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitGet_excep_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Get_excep_exprContext get_excep_expr() throws RecognitionException {
		Get_excep_exprContext _localctx = new Get_excep_exprContext(_ctx, getState());
		enterRule(_localctx, 214, RULE_get_excep_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(987); match(KW_GETRAISES);
			setState(988); exception_list();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Set_excep_exprContext extends ParserRuleContext {
		public TerminalNode KW_SETRAISES() { return getToken(IDLParser.KW_SETRAISES, 0); }
		public Exception_listContext exception_list() {
			return getRuleContext(Exception_listContext.class,0);
		}
		public Set_excep_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_set_excep_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSet_excep_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Set_excep_exprContext set_excep_expr() throws RecognitionException {
		Set_excep_exprContext _localctx = new Set_excep_exprContext(_ctx, getState());
		enterRule(_localctx, 216, RULE_set_excep_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(990); match(KW_SETRAISES);
			setState(991); exception_list();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Exception_listContext extends ParserRuleContext {
		public List<Scoped_nameContext> scoped_name() {
			return getRuleContexts(Scoped_nameContext.class);
		}
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public Scoped_nameContext scoped_name(int i) {
			return getRuleContext(Scoped_nameContext.class,i);
		}
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public Exception_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exception_list; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitException_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Exception_listContext exception_list() throws RecognitionException {
		Exception_listContext _localctx = new Exception_listContext(_ctx, getState());
		enterRule(_localctx, 218, RULE_exception_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(993); match(LEFT_BRACKET);
			setState(994); scoped_name();
			setState(999);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(995); match(COMA);
				setState(996); scoped_name();
				}
				}
				setState(1001);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1002); match(RIGHT_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ComponentContext extends ParserRuleContext {
		public Component_forward_declContext component_forward_decl() {
			return getRuleContext(Component_forward_declContext.class,0);
		}
		public Component_declContext component_decl() {
			return getRuleContext(Component_declContext.class,0);
		}
		public ComponentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComponent(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ComponentContext component() throws RecognitionException {
		ComponentContext _localctx = new ComponentContext(_ctx, getState());
		enterRule(_localctx, 220, RULE_component);
		try {
			setState(1006);
			switch ( getInterpreter().adaptivePredict(_input,78,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1004); component_decl();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1005); component_forward_decl();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Component_forward_declContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_COMPONENT() { return getToken(IDLParser.KW_COMPONENT, 0); }
		public Component_forward_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component_forward_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComponent_forward_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Component_forward_declContext component_forward_decl() throws RecognitionException {
		Component_forward_declContext _localctx = new Component_forward_declContext(_ctx, getState());
		enterRule(_localctx, 222, RULE_component_forward_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1008); match(KW_COMPONENT);
			setState(1009); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Component_declContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public Component_headerContext component_header() {
			return getRuleContext(Component_headerContext.class,0);
		}
		public Component_bodyContext component_body() {
			return getRuleContext(Component_bodyContext.class,0);
		}
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Component_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComponent_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Component_declContext component_decl() throws RecognitionException {
		Component_declContext _localctx = new Component_declContext(_ctx, getState());
		enterRule(_localctx, 224, RULE_component_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1011); component_header();
			setState(1012); match(LEFT_BRACE);
			setState(1013); component_body();
			setState(1014); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Component_headerContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_COMPONENT() { return getToken(IDLParser.KW_COMPONENT, 0); }
		public Component_inheritance_specContext component_inheritance_spec() {
			return getRuleContext(Component_inheritance_specContext.class,0);
		}
		public Supported_interface_specContext supported_interface_spec() {
			return getRuleContext(Supported_interface_specContext.class,0);
		}
		public Component_headerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component_header; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComponent_header(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Component_headerContext component_header() throws RecognitionException {
		Component_headerContext _localctx = new Component_headerContext(_ctx, getState());
		enterRule(_localctx, 226, RULE_component_header);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1016); match(KW_COMPONENT);
			setState(1017); match(ID);
			setState(1019);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(1018); component_inheritance_spec();
				}
			}

			setState(1022);
			_la = _input.LA(1);
			if (_la==KW_SUPPORTS) {
				{
				setState(1021); supported_interface_spec();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Supported_interface_specContext extends ParserRuleContext {
		public TerminalNode KW_SUPPORTS() { return getToken(IDLParser.KW_SUPPORTS, 0); }
		public List<Scoped_nameContext> scoped_name() {
			return getRuleContexts(Scoped_nameContext.class);
		}
		public List<TerminalNode> COMA() { return getTokens(IDLParser.COMA); }
		public TerminalNode COMA(int i) {
			return getToken(IDLParser.COMA, i);
		}
		public Scoped_nameContext scoped_name(int i) {
			return getRuleContext(Scoped_nameContext.class,i);
		}
		public Supported_interface_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_supported_interface_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitSupported_interface_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Supported_interface_specContext supported_interface_spec() throws RecognitionException {
		Supported_interface_specContext _localctx = new Supported_interface_specContext(_ctx, getState());
		enterRule(_localctx, 228, RULE_supported_interface_spec);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1024); match(KW_SUPPORTS);
			setState(1025); scoped_name();
			setState(1030);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMA) {
				{
				{
				setState(1026); match(COMA);
				setState(1027); scoped_name();
				}
				}
				setState(1032);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Component_inheritance_specContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode COLON() { return getToken(IDLParser.COLON, 0); }
		public Component_inheritance_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component_inheritance_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComponent_inheritance_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Component_inheritance_specContext component_inheritance_spec() throws RecognitionException {
		Component_inheritance_specContext _localctx = new Component_inheritance_specContext(_ctx, getState());
		enterRule(_localctx, 230, RULE_component_inheritance_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1033); match(COLON);
			setState(1034); scoped_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Component_bodyContext extends ParserRuleContext {
		public Component_exportContext component_export(int i) {
			return getRuleContext(Component_exportContext.class,i);
		}
		public List<Component_exportContext> component_export() {
			return getRuleContexts(Component_exportContext.class);
		}
		public Component_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component_body; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComponent_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Component_bodyContext component_body() throws RecognitionException {
		Component_bodyContext _localctx = new Component_bodyContext(_ctx, getState());
		enterRule(_localctx, 232, RULE_component_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1039);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 39)) & ~0x3f) == 0 && ((1L << (_la - 39)) & ((1L << (KW_EMITS - 39)) | (1L << (KW_PUBLISHES - 39)) | (1L << (KW_USES - 39)) | (1L << (KW_READONLY - 39)) | (1L << (KW_PROVIDES - 39)) | (1L << (KW_CONSUMES - 39)) | (1L << (KW_ATTRIBUTE - 39)))) != 0)) {
				{
				{
				setState(1036); component_export();
				}
				}
				setState(1041);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Component_exportContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public Emits_declContext emits_decl() {
			return getRuleContext(Emits_declContext.class,0);
		}
		public Publishes_declContext publishes_decl() {
			return getRuleContext(Publishes_declContext.class,0);
		}
		public Attr_declContext attr_decl() {
			return getRuleContext(Attr_declContext.class,0);
		}
		public Provides_declContext provides_decl() {
			return getRuleContext(Provides_declContext.class,0);
		}
		public Consumes_declContext consumes_decl() {
			return getRuleContext(Consumes_declContext.class,0);
		}
		public Uses_declContext uses_decl() {
			return getRuleContext(Uses_declContext.class,0);
		}
		public Component_exportContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component_export; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitComponent_export(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Component_exportContext component_export() throws RecognitionException {
		Component_exportContext _localctx = new Component_exportContext(_ctx, getState());
		enterRule(_localctx, 234, RULE_component_export);
		try {
			setState(1060);
			switch (_input.LA(1)) {
			case KW_PROVIDES:
				enterOuterAlt(_localctx, 1);
				{
				setState(1042); provides_decl();
				setState(1043); match(SEMICOLON);
				}
				break;
			case KW_USES:
				enterOuterAlt(_localctx, 2);
				{
				setState(1045); uses_decl();
				setState(1046); match(SEMICOLON);
				}
				break;
			case KW_EMITS:
				enterOuterAlt(_localctx, 3);
				{
				setState(1048); emits_decl();
				setState(1049); match(SEMICOLON);
				}
				break;
			case KW_PUBLISHES:
				enterOuterAlt(_localctx, 4);
				{
				setState(1051); publishes_decl();
				setState(1052); match(SEMICOLON);
				}
				break;
			case KW_CONSUMES:
				enterOuterAlt(_localctx, 5);
				{
				setState(1054); consumes_decl();
				setState(1055); match(SEMICOLON);
				}
				break;
			case KW_READONLY:
			case KW_ATTRIBUTE:
				enterOuterAlt(_localctx, 6);
				{
				setState(1057); attr_decl();
				setState(1058); match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Provides_declContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_PROVIDES() { return getToken(IDLParser.KW_PROVIDES, 0); }
		public Interface_typeContext interface_type() {
			return getRuleContext(Interface_typeContext.class,0);
		}
		public Provides_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_provides_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitProvides_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Provides_declContext provides_decl() throws RecognitionException {
		Provides_declContext _localctx = new Provides_declContext(_ctx, getState());
		enterRule(_localctx, 236, RULE_provides_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1062); match(KW_PROVIDES);
			setState(1063); interface_type();
			setState(1064); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_typeContext extends ParserRuleContext {
		public TerminalNode KW_OBJECT() { return getToken(IDLParser.KW_OBJECT, 0); }
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public Interface_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitInterface_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Interface_typeContext interface_type() throws RecognitionException {
		Interface_typeContext _localctx = new Interface_typeContext(_ctx, getState());
		enterRule(_localctx, 238, RULE_interface_type);
		try {
			setState(1068);
			switch (_input.LA(1)) {
			case DOUBLE_COLON:
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(1066); scoped_name();
				}
				break;
			case KW_OBJECT:
				enterOuterAlt(_localctx, 2);
				{
				setState(1067); match(KW_OBJECT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Uses_declContext extends ParserRuleContext {
		public TerminalNode KW_MULTIPLE() { return getToken(IDLParser.KW_MULTIPLE, 0); }
		public TerminalNode KW_USES() { return getToken(IDLParser.KW_USES, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Interface_typeContext interface_type() {
			return getRuleContext(Interface_typeContext.class,0);
		}
		public Uses_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_uses_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitUses_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Uses_declContext uses_decl() throws RecognitionException {
		Uses_declContext _localctx = new Uses_declContext(_ctx, getState());
		enterRule(_localctx, 240, RULE_uses_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1070); match(KW_USES);
			setState(1072);
			_la = _input.LA(1);
			if (_la==KW_MULTIPLE) {
				{
				setState(1071); match(KW_MULTIPLE);
				}
			}

			setState(1074); interface_type();
			setState(1075); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Emits_declContext extends ParserRuleContext {
		public TerminalNode KW_EMITS() { return getToken(IDLParser.KW_EMITS, 0); }
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Emits_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_emits_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEmits_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Emits_declContext emits_decl() throws RecognitionException {
		Emits_declContext _localctx = new Emits_declContext(_ctx, getState());
		enterRule(_localctx, 242, RULE_emits_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1077); match(KW_EMITS);
			setState(1078); scoped_name();
			setState(1079); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Publishes_declContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_PUBLISHES() { return getToken(IDLParser.KW_PUBLISHES, 0); }
		public Publishes_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_publishes_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitPublishes_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Publishes_declContext publishes_decl() throws RecognitionException {
		Publishes_declContext _localctx = new Publishes_declContext(_ctx, getState());
		enterRule(_localctx, 244, RULE_publishes_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1081); match(KW_PUBLISHES);
			setState(1082); scoped_name();
			setState(1083); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Consumes_declContext extends ParserRuleContext {
		public TerminalNode KW_CONSUMES() { return getToken(IDLParser.KW_CONSUMES, 0); }
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Consumes_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_consumes_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitConsumes_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Consumes_declContext consumes_decl() throws RecognitionException {
		Consumes_declContext _localctx = new Consumes_declContext(_ctx, getState());
		enterRule(_localctx, 246, RULE_consumes_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1085); match(KW_CONSUMES);
			setState(1086); scoped_name();
			setState(1087); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Home_declContext extends ParserRuleContext {
		public Home_headerContext home_header() {
			return getRuleContext(Home_headerContext.class,0);
		}
		public Home_bodyContext home_body() {
			return getRuleContext(Home_bodyContext.class,0);
		}
		public Home_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_home_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitHome_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Home_declContext home_decl() throws RecognitionException {
		Home_declContext _localctx = new Home_declContext(_ctx, getState());
		enterRule(_localctx, 248, RULE_home_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1089); home_header();
			setState(1090); home_body();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Home_headerContext extends ParserRuleContext {
		public Primary_key_specContext primary_key_spec() {
			return getRuleContext(Primary_key_specContext.class,0);
		}
		public TerminalNode KW_HOME() { return getToken(IDLParser.KW_HOME, 0); }
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_MANAGES() { return getToken(IDLParser.KW_MANAGES, 0); }
		public Supported_interface_specContext supported_interface_spec() {
			return getRuleContext(Supported_interface_specContext.class,0);
		}
		public Home_inheritance_specContext home_inheritance_spec() {
			return getRuleContext(Home_inheritance_specContext.class,0);
		}
		public Home_headerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_home_header; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitHome_header(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Home_headerContext home_header() throws RecognitionException {
		Home_headerContext _localctx = new Home_headerContext(_ctx, getState());
		enterRule(_localctx, 250, RULE_home_header);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1092); match(KW_HOME);
			setState(1093); match(ID);
			setState(1095);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(1094); home_inheritance_spec();
				}
			}

			setState(1098);
			_la = _input.LA(1);
			if (_la==KW_SUPPORTS) {
				{
				setState(1097); supported_interface_spec();
				}
			}

			setState(1100); match(KW_MANAGES);
			setState(1101); scoped_name();
			setState(1103);
			_la = _input.LA(1);
			if (_la==KW_PRIMARYKEY) {
				{
				setState(1102); primary_key_spec();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Home_inheritance_specContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode COLON() { return getToken(IDLParser.COLON, 0); }
		public Home_inheritance_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_home_inheritance_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitHome_inheritance_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Home_inheritance_specContext home_inheritance_spec() throws RecognitionException {
		Home_inheritance_specContext _localctx = new Home_inheritance_specContext(_ctx, getState());
		enterRule(_localctx, 252, RULE_home_inheritance_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1105); match(COLON);
			setState(1106); scoped_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Primary_key_specContext extends ParserRuleContext {
		public Scoped_nameContext scoped_name() {
			return getRuleContext(Scoped_nameContext.class,0);
		}
		public TerminalNode KW_PRIMARYKEY() { return getToken(IDLParser.KW_PRIMARYKEY, 0); }
		public Primary_key_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary_key_spec; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitPrimary_key_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Primary_key_specContext primary_key_spec() throws RecognitionException {
		Primary_key_specContext _localctx = new Primary_key_specContext(_ctx, getState());
		enterRule(_localctx, 254, RULE_primary_key_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1108); match(KW_PRIMARYKEY);
			setState(1109); scoped_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Home_bodyContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public List<Home_exportContext> home_export() {
			return getRuleContexts(Home_exportContext.class);
		}
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Home_exportContext home_export(int i) {
			return getRuleContext(Home_exportContext.class,i);
		}
		public Home_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_home_body; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitHome_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Home_bodyContext home_body() throws RecognitionException {
		Home_bodyContext _localctx = new Home_bodyContext(_ctx, getState());
		enterRule(_localctx, 256, RULE_home_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1111); match(LEFT_BRACE);
			setState(1115);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_TYPEDEF) | (1L << KW_OCTET) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_READONLY) | (1L << KW_FINDER) | (1L << KW_VOID) | (1L << KW_WCHAR) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_FACTORY - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ONEWAY - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_ATTRIBUTE - 64)) | (1L << (ID - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0)) {
				{
				{
				setState(1112); home_export();
				}
				}
				setState(1117);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1118); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Home_exportContext extends ParserRuleContext {
		public Factory_declContext factory_decl() {
			return getRuleContext(Factory_declContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(IDLParser.SEMICOLON, 0); }
		public Finder_declContext finder_decl() {
			return getRuleContext(Finder_declContext.class,0);
		}
		public ExportContext export() {
			return getRuleContext(ExportContext.class,0);
		}
		public Home_exportContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_home_export; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitHome_export(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Home_exportContext home_export() throws RecognitionException {
		Home_exportContext _localctx = new Home_exportContext(_ctx, getState());
		enterRule(_localctx, 258, RULE_home_export);
		try {
			setState(1127);
			switch (_input.LA(1)) {
			case DOUBLE_COLON:
			case KW_STRING:
			case KW_TYPEDEF:
			case KW_OCTET:
			case KW_STRUCT:
			case KW_NATIVE:
			case KW_READONLY:
			case KW_VOID:
			case KW_WCHAR:
			case KW_SHORT:
			case KW_LONG:
			case KW_ENUM:
			case KW_WSTRING:
			case KW_EXCEPTION:
			case KW_CONST:
			case KW_VALUEBASE:
			case KW_OBJECT:
			case KW_UNSIGNED:
			case KW_UNION:
			case KW_ONEWAY:
			case KW_ANY:
			case KW_CHAR:
			case KW_FLOAT:
			case KW_BOOLEAN:
			case KW_DOUBLE:
			case KW_TYPEPREFIX:
			case KW_TYPEID:
			case KW_ATTRIBUTE:
			case ID:
			case LINE_PRAGMA:
				enterOuterAlt(_localctx, 1);
				{
				setState(1120); export();
				}
				break;
			case KW_FACTORY:
				enterOuterAlt(_localctx, 2);
				{
				setState(1121); factory_decl();
				setState(1122); match(SEMICOLON);
				}
				break;
			case KW_FINDER:
				enterOuterAlt(_localctx, 3);
				{
				setState(1124); finder_decl();
				setState(1125); match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Factory_declContext extends ParserRuleContext {
		public Raises_exprContext raises_expr() {
			return getRuleContext(Raises_exprContext.class,0);
		}
		public TerminalNode KW_FACTORY() { return getToken(IDLParser.KW_FACTORY, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Init_param_declsContext init_param_decls() {
			return getRuleContext(Init_param_declsContext.class,0);
		}
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public Factory_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factory_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitFactory_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Factory_declContext factory_decl() throws RecognitionException {
		Factory_declContext _localctx = new Factory_declContext(_ctx, getState());
		enterRule(_localctx, 260, RULE_factory_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1129); match(KW_FACTORY);
			setState(1130); match(ID);
			setState(1131); match(LEFT_BRACKET);
			setState(1133);
			_la = _input.LA(1);
			if (_la==KW_IN) {
				{
				setState(1132); init_param_decls();
				}
			}

			setState(1135); match(RIGHT_BRACKET);
			setState(1137);
			_la = _input.LA(1);
			if (_la==KW_RAISES) {
				{
				setState(1136); raises_expr();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Finder_declContext extends ParserRuleContext {
		public TerminalNode KW_FINDER() { return getToken(IDLParser.KW_FINDER, 0); }
		public Raises_exprContext raises_expr() {
			return getRuleContext(Raises_exprContext.class,0);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Init_param_declsContext init_param_decls() {
			return getRuleContext(Init_param_declsContext.class,0);
		}
		public TerminalNode LEFT_BRACKET() { return getToken(IDLParser.LEFT_BRACKET, 0); }
		public TerminalNode RIGHT_BRACKET() { return getToken(IDLParser.RIGHT_BRACKET, 0); }
		public Finder_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_finder_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitFinder_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Finder_declContext finder_decl() throws RecognitionException {
		Finder_declContext _localctx = new Finder_declContext(_ctx, getState());
		enterRule(_localctx, 262, RULE_finder_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1139); match(KW_FINDER);
			setState(1140); match(ID);
			setState(1141); match(LEFT_BRACKET);
			setState(1143);
			_la = _input.LA(1);
			if (_la==KW_IN) {
				{
				setState(1142); init_param_decls();
				}
			}

			setState(1145); match(RIGHT_BRACKET);
			setState(1147);
			_la = _input.LA(1);
			if (_la==KW_RAISES) {
				{
				setState(1146); raises_expr();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EventContext extends ParserRuleContext {
		public Event_declContext event_decl() {
			return getRuleContext(Event_declContext.class,0);
		}
		public Event_abs_declContext event_abs_decl() {
			return getRuleContext(Event_abs_declContext.class,0);
		}
		public Event_forward_declContext event_forward_decl() {
			return getRuleContext(Event_forward_declContext.class,0);
		}
		public EventContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_event; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEvent(this);
			else return visitor.visitChildren(this);
		}
	}

	public final EventContext event() throws RecognitionException {
		EventContext _localctx = new EventContext(_ctx, getState());
		enterRule(_localctx, 264, RULE_event);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1152);
			switch ( getInterpreter().adaptivePredict(_input,95,_ctx) ) {
			case 1:
				{
				setState(1149); event_decl();
				}
				break;
			case 2:
				{
				setState(1150); event_abs_decl();
				}
				break;
			case 3:
				{
				setState(1151); event_forward_decl();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Event_forward_declContext extends ParserRuleContext {
		public TerminalNode KW_ABSTRACT() { return getToken(IDLParser.KW_ABSTRACT, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_EVENTTYPE() { return getToken(IDLParser.KW_EVENTTYPE, 0); }
		public Event_forward_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_event_forward_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEvent_forward_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Event_forward_declContext event_forward_decl() throws RecognitionException {
		Event_forward_declContext _localctx = new Event_forward_declContext(_ctx, getState());
		enterRule(_localctx, 266, RULE_event_forward_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1155);
			_la = _input.LA(1);
			if (_la==KW_ABSTRACT) {
				{
				setState(1154); match(KW_ABSTRACT);
				}
			}

			setState(1157); match(KW_EVENTTYPE);
			setState(1158); match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Event_abs_declContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public ExportContext export(int i) {
			return getRuleContext(ExportContext.class,i);
		}
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public TerminalNode KW_ABSTRACT() { return getToken(IDLParser.KW_ABSTRACT, 0); }
		public List<ExportContext> export() {
			return getRuleContexts(ExportContext.class);
		}
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Value_inheritance_specContext value_inheritance_spec() {
			return getRuleContext(Value_inheritance_specContext.class,0);
		}
		public TerminalNode KW_EVENTTYPE() { return getToken(IDLParser.KW_EVENTTYPE, 0); }
		public Event_abs_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_event_abs_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEvent_abs_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Event_abs_declContext event_abs_decl() throws RecognitionException {
		Event_abs_declContext _localctx = new Event_abs_declContext(_ctx, getState());
		enterRule(_localctx, 268, RULE_event_abs_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1160); match(KW_ABSTRACT);
			setState(1161); match(KW_EVENTTYPE);
			setState(1162); match(ID);
			setState(1163); value_inheritance_spec();
			setState(1164); match(LEFT_BRACE);
			setState(1168);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_TYPEDEF) | (1L << KW_OCTET) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_READONLY) | (1L << KW_VOID) | (1L << KW_WCHAR) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ONEWAY - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_ATTRIBUTE - 64)) | (1L << (ID - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0)) {
				{
				{
				setState(1165); export();
				}
				}
				setState(1170);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1171); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Event_declContext extends ParserRuleContext {
		public TerminalNode RIGHT_BRACE() { return getToken(IDLParser.RIGHT_BRACE, 0); }
		public Event_headerContext event_header() {
			return getRuleContext(Event_headerContext.class,0);
		}
		public Value_elementContext value_element(int i) {
			return getRuleContext(Value_elementContext.class,i);
		}
		public List<Value_elementContext> value_element() {
			return getRuleContexts(Value_elementContext.class);
		}
		public TerminalNode LEFT_BRACE() { return getToken(IDLParser.LEFT_BRACE, 0); }
		public Event_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_event_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEvent_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Event_declContext event_decl() throws RecognitionException {
		Event_declContext _localctx = new Event_declContext(_ctx, getState());
		enterRule(_localctx, 270, RULE_event_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1173); event_header();
			setState(1174); match(LEFT_BRACE);
			setState(1178);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DOUBLE_COLON) | (1L << KW_STRING) | (1L << KW_TYPEDEF) | (1L << KW_OCTET) | (1L << KW_STRUCT) | (1L << KW_NATIVE) | (1L << KW_READONLY) | (1L << KW_VOID) | (1L << KW_PRIVATE) | (1L << KW_WCHAR) | (1L << KW_PUBLIC) | (1L << KW_SHORT) | (1L << KW_LONG))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (KW_ENUM - 64)) | (1L << (KW_WSTRING - 64)) | (1L << (KW_FACTORY - 64)) | (1L << (KW_EXCEPTION - 64)) | (1L << (KW_CONST - 64)) | (1L << (KW_VALUEBASE - 64)) | (1L << (KW_OBJECT - 64)) | (1L << (KW_UNSIGNED - 64)) | (1L << (KW_UNION - 64)) | (1L << (KW_ONEWAY - 64)) | (1L << (KW_ANY - 64)) | (1L << (KW_CHAR - 64)) | (1L << (KW_FLOAT - 64)) | (1L << (KW_BOOLEAN - 64)) | (1L << (KW_DOUBLE - 64)) | (1L << (KW_TYPEPREFIX - 64)) | (1L << (KW_TYPEID - 64)) | (1L << (KW_ATTRIBUTE - 64)) | (1L << (ID - 64)) | (1L << (LINE_PRAGMA - 64)))) != 0)) {
				{
				{
				setState(1175); value_element();
				}
				}
				setState(1180);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1181); match(RIGHT_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Event_headerContext extends ParserRuleContext {
		public TerminalNode KW_CUSTOM() { return getToken(IDLParser.KW_CUSTOM, 0); }
		public TerminalNode ID() { return getToken(IDLParser.ID, 0); }
		public Value_inheritance_specContext value_inheritance_spec() {
			return getRuleContext(Value_inheritance_specContext.class,0);
		}
		public TerminalNode KW_EVENTTYPE() { return getToken(IDLParser.KW_EVENTTYPE, 0); }
		public Event_headerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_event_header; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitEvent_header(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Event_headerContext event_header() throws RecognitionException {
		Event_headerContext _localctx = new Event_headerContext(_ctx, getState());
		enterRule(_localctx, 272, RULE_event_header);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1184);
			_la = _input.LA(1);
			if (_la==KW_CUSTOM) {
				{
				setState(1183); match(KW_CUSTOM);
				}
			}

			setState(1186); match(KW_EVENTTYPE);
			setState(1187); match(ID);
			setState(1188); value_inheritance_spec();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Pragma_declContext extends ParserRuleContext {
		public TerminalNode LINE_PRAGMA() { return getToken(IDLParser.LINE_PRAGMA, 0); }
		public Pragma_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pragma_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitPragma_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Pragma_declContext pragma_decl() throws RecognitionException {
		Pragma_declContext _localctx = new Pragma_declContext(_ctx, getState());
		enterRule(_localctx, 274, RULE_pragma_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1190); match(LINE_PRAGMA);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Codepos_declContext extends ParserRuleContext {
		public TerminalNode CODEPOS() { return getToken(IDLParser.CODEPOS, 0); }
		public Codepos_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_codepos_decl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof IDLVisitor ) return ((IDLVisitor<? extends T>)visitor).visitCodepos_decl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Codepos_declContext codepos_decl() throws RecognitionException {
		Codepos_declContext _localctx = new Codepos_declContext(_ctx, getState());
		enterRule(_localctx, 276, RULE_codepos_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1192); match(CODEPOS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3j\u04ad\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\4R\tR\4S\tS\4T\tT"+
		"\4U\tU\4V\tV\4W\tW\4X\tX\4Y\tY\4Z\tZ\4[\t[\4\\\t\\\4]\t]\4^\t^\4_\t_\4"+
		"`\t`\4a\ta\4b\tb\4c\tc\4d\td\4e\te\4f\tf\4g\tg\4h\th\4i\ti\4j\tj\4k\t"+
		"k\4l\tl\4m\tm\4n\tn\4o\to\4p\tp\4q\tq\4r\tr\4s\ts\4t\tt\4u\tu\4v\tv\4"+
		"w\tw\4x\tx\4y\ty\4z\tz\4{\t{\4|\t|\4}\t}\4~\t~\4\177\t\177\4\u0080\t\u0080"+
		"\4\u0081\t\u0081\4\u0082\t\u0082\4\u0083\t\u0083\4\u0084\t\u0084\4\u0085"+
		"\t\u0085\4\u0086\t\u0086\4\u0087\t\u0087\4\u0088\t\u0088\4\u0089\t\u0089"+
		"\4\u008a\t\u008a\4\u008b\t\u008b\4\u008c\t\u008c\3\2\7\2\u011a\n\2\f\2"+
		"\16\2\u011d\13\2\3\2\6\2\u0120\n\2\r\2\16\2\u0121\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3\u0147\n\3\3\4\3"+
		"\4\3\4\3\4\6\4\u014d\n\4\r\4\16\4\u014e\3\4\3\4\3\5\3\5\5\5\u0155\n\5"+
		"\3\6\3\6\3\6\3\6\3\6\3\7\5\7\u015d\n\7\3\7\3\7\3\7\3\b\5\b\u0163\n\b\3"+
		"\b\3\b\3\b\5\b\u0168\n\b\3\t\7\t\u016b\n\t\f\t\16\t\u016e\13\t\3\n\3\n"+
		"\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3"+
		"\n\3\n\3\n\5\n\u0186\n\n\3\13\3\13\3\13\3\13\7\13\u018c\n\13\f\13\16\13"+
		"\u018f\13\13\3\f\3\f\3\r\5\r\u0194\n\r\3\r\3\r\3\r\7\r\u0199\n\r\f\r\16"+
		"\r\u019c\13\r\3\16\3\16\3\16\3\16\5\16\u01a2\n\16\3\17\5\17\u01a5\n\17"+
		"\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\21\7\21"+
		"\u01b4\n\21\f\21\16\21\u01b7\13\21\3\21\3\21\3\22\3\22\3\22\7\22\u01be"+
		"\n\22\f\22\16\22\u01c1\13\22\3\22\3\22\3\23\5\23\u01c6\n\23\3\23\3\23"+
		"\3\23\3\23\3\24\3\24\5\24\u01ce\n\24\3\24\3\24\3\24\7\24\u01d3\n\24\f"+
		"\24\16\24\u01d6\13\24\5\24\u01d8\n\24\3\24\3\24\3\24\3\24\7\24\u01de\n"+
		"\24\f\24\16\24\u01e1\13\24\5\24\u01e3\n\24\3\25\3\25\3\26\3\26\3\26\5"+
		"\26\u01ea\n\26\3\27\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\5\30\u01f5"+
		"\n\30\3\30\3\30\5\30\u01f9\n\30\3\30\3\30\3\31\3\31\3\31\7\31\u0200\n"+
		"\31\f\31\16\31\u0203\13\31\3\32\3\32\3\32\3\32\3\33\3\33\3\34\3\34\3\34"+
		"\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\5\35"+
		"\u021b\n\35\3\36\3\36\3\37\3\37\3\37\7\37\u0222\n\37\f\37\16\37\u0225"+
		"\13\37\3 \3 \3 \7 \u022a\n \f \16 \u022d\13 \3!\3!\3!\7!\u0232\n!\f!\16"+
		"!\u0235\13!\3\"\3\"\3\"\7\"\u023a\n\"\f\"\16\"\u023d\13\"\3#\3#\3#\7#"+
		"\u0242\n#\f#\16#\u0245\13#\3$\3$\3$\7$\u024a\n$\f$\16$\u024d\13$\3%\3"+
		"%\3%\3%\5%\u0253\n%\3&\3&\3\'\3\'\3\'\3\'\3\'\3\'\5\'\u025d\n\'\3(\3("+
		"\3)\3)\3*\3*\3*\3*\3*\3*\3*\3*\5*\u026b\n*\3+\3+\3+\3,\3,\5,\u0272\n,"+
		"\3-\3-\3-\5-\u0277\n-\3.\3.\3.\3.\3.\3.\3.\3.\3.\5.\u0282\n.\3/\3/\3/"+
		"\3/\5/\u0288\n/\3\60\3\60\3\60\5\60\u028d\n\60\3\61\3\61\3\61\7\61\u0292"+
		"\n\61\f\61\16\61\u0295\13\61\3\62\3\62\5\62\u0299\n\62\3\63\3\63\3\64"+
		"\3\64\3\65\3\65\3\65\3\65\5\65\u02a3\n\65\3\66\3\66\5\66\u02a7\n\66\3"+
		"\67\3\67\3\67\5\67\u02ac\n\67\38\38\39\39\3:\3:\3:\3;\3;\3;\5;\u02b8\n"+
		";\3<\3<\3<\3=\3=\3=\3>\3>\3>\3>\3?\3?\3@\3@\3A\3A\3B\3B\3C\3C\3D\3D\3"+
		"E\3E\3E\3E\3E\3E\3F\6F\u02d7\nF\rF\16F\u02d8\3G\3G\3G\3G\3H\3H\3H\3H\3"+
		"H\3H\3H\3H\3H\3H\3I\3I\3I\3I\3I\5I\u02ee\nI\3J\6J\u02f1\nJ\rJ\16J\u02f2"+
		"\3K\6K\u02f6\nK\rK\16K\u02f7\3K\3K\3K\3L\3L\3L\3L\3L\3L\5L\u0303\nL\3"+
		"M\3M\3M\3N\3N\3N\3N\3N\3N\7N\u030e\nN\fN\16N\u0311\13N\3N\3N\3O\3O\3P"+
		"\3P\3P\3P\3P\3P\3P\3P\3P\3P\3P\3P\5P\u0323\nP\3Q\3Q\3Q\3Q\3Q\3Q\5Q\u032b"+
		"\nQ\3R\3R\3R\3R\3R\3R\5R\u0333\nR\3S\3S\6S\u0337\nS\rS\16S\u0338\3T\3"+
		"T\3T\3T\3U\3U\5U\u0341\nU\3V\3V\3V\3V\7V\u0347\nV\fV\16V\u034a\13V\3V"+
		"\3V\3W\5W\u034f\nW\3W\3W\3W\3W\5W\u0355\nW\3W\5W\u0358\nW\3X\3X\3Y\3Y"+
		"\5Y\u035e\nY\3Z\3Z\3Z\3Z\7Z\u0364\nZ\fZ\16Z\u0367\13Z\3Z\3Z\3Z\3Z\5Z\u036d"+
		"\nZ\3[\3[\3[\3[\3\\\3\\\3]\3]\3]\3]\3]\7]\u037a\n]\f]\16]\u037d\13]\3"+
		"]\3]\3^\3^\3^\3^\3^\7^\u0386\n^\f^\16^\u0389\13^\3^\3^\3_\3_\3_\3_\5_"+
		"\u0391\n_\3`\3`\3`\3`\3`\3`\3`\3a\3a\3b\3b\3c\3c\3c\3c\5c\u03a2\nc\3d"+
		"\3d\3d\3d\3e\3e\5e\u03aa\ne\3f\3f\3f\3f\3g\3g\3g\3g\3h\3h\3h\3h\3h\3i"+
		"\3i\3i\3i\3i\3i\7i\u03bf\ni\fi\16i\u03c2\13i\5i\u03c4\ni\3j\3j\3j\3j\3"+
		"k\3k\3k\3k\3k\3k\7k\u03d0\nk\fk\16k\u03d3\13k\5k\u03d5\nk\3l\3l\5l\u03d9"+
		"\nl\3l\5l\u03dc\nl\3m\3m\3m\3n\3n\3n\3o\3o\3o\3o\7o\u03e8\no\fo\16o\u03eb"+
		"\13o\3o\3o\3p\3p\5p\u03f1\np\3q\3q\3q\3r\3r\3r\3r\3r\3s\3s\3s\5s\u03fe"+
		"\ns\3s\5s\u0401\ns\3t\3t\3t\3t\7t\u0407\nt\ft\16t\u040a\13t\3u\3u\3u\3"+
		"v\7v\u0410\nv\fv\16v\u0413\13v\3w\3w\3w\3w\3w\3w\3w\3w\3w\3w\3w\3w\3w"+
		"\3w\3w\3w\3w\3w\5w\u0427\nw\3x\3x\3x\3x\3y\3y\5y\u042f\ny\3z\3z\5z\u0433"+
		"\nz\3z\3z\3z\3{\3{\3{\3{\3|\3|\3|\3|\3}\3}\3}\3}\3~\3~\3~\3\177\3\177"+
		"\3\177\5\177\u044a\n\177\3\177\5\177\u044d\n\177\3\177\3\177\3\177\5\177"+
		"\u0452\n\177\3\u0080\3\u0080\3\u0080\3\u0081\3\u0081\3\u0081\3\u0082\3"+
		"\u0082\7\u0082\u045c\n\u0082\f\u0082\16\u0082\u045f\13\u0082\3\u0082\3"+
		"\u0082\3\u0083\3\u0083\3\u0083\3\u0083\3\u0083\3\u0083\3\u0083\5\u0083"+
		"\u046a\n\u0083\3\u0084\3\u0084\3\u0084\3\u0084\5\u0084\u0470\n\u0084\3"+
		"\u0084\3\u0084\5\u0084\u0474\n\u0084\3\u0085\3\u0085\3\u0085\3\u0085\5"+
		"\u0085\u047a\n\u0085\3\u0085\3\u0085\5\u0085\u047e\n\u0085\3\u0086\3\u0086"+
		"\3\u0086\5\u0086\u0483\n\u0086\3\u0087\5\u0087\u0486\n\u0087\3\u0087\3"+
		"\u0087\3\u0087\3\u0088\3\u0088\3\u0088\3\u0088\3\u0088\3\u0088\7\u0088"+
		"\u0491\n\u0088\f\u0088\16\u0088\u0494\13\u0088\3\u0088\3\u0088\3\u0089"+
		"\3\u0089\3\u0089\7\u0089\u049b\n\u0089\f\u0089\16\u0089\u049e\13\u0089"+
		"\3\u0089\3\u0089\3\u008a\5\u008a\u04a3\n\u008a\3\u008a\3\u008a\3\u008a"+
		"\3\u008a\3\u008b\3\u008b\3\u008c\3\u008c\3\u008c\2\2\u008d\2\4\6\b\n\f"+
		"\16\20\22\24\26\30\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^"+
		"`bdfhjlnprtvxz|~\u0080\u0082\u0084\u0086\u0088\u008a\u008c\u008e\u0090"+
		"\u0092\u0094\u0096\u0098\u009a\u009c\u009e\u00a0\u00a2\u00a4\u00a6\u00a8"+
		"\u00aa\u00ac\u00ae\u00b0\u00b2\u00b4\u00b6\u00b8\u00ba\u00bc\u00be\u00c0"+
		"\u00c2\u00c4\u00c6\u00c8\u00ca\u00cc\u00ce\u00d0\u00d2\u00d4\u00d6\u00d8"+
		"\u00da\u00dc\u00de\u00e0\u00e2\u00e4\u00e6\u00e8\u00ea\u00ec\u00ee\u00f0"+
		"\u00f2\u00f4\u00f6\u00f8\u00fa\u00fc\u00fe\u0100\u0102\u0104\u0106\u0108"+
		"\u010a\u010c\u010e\u0110\u0112\u0114\u0116\2\n\4\2ZZbb\4\2::??\3\2%&\3"+
		"\2\34\35\5\2\30\30\33\33\"\"\4\2\27\27\34\35\3\2\4\r\5\2((==[[\u04bf\2"+
		"\u011b\3\2\2\2\4\u0146\3\2\2\2\6\u0148\3\2\2\2\b\u0154\3\2\2\2\n\u0156"+
		"\3\2\2\2\f\u015c\3\2\2\2\16\u0162\3\2\2\2\20\u016c\3\2\2\2\22\u0185\3"+
		"\2\2\2\24\u0187\3\2\2\2\26\u0190\3\2\2\2\30\u0193\3\2\2\2\32\u01a1\3\2"+
		"\2\2\34\u01a4\3\2\2\2\36\u01a9\3\2\2\2 \u01ad\3\2\2\2\"\u01ba\3\2\2\2"+
		"$\u01c5\3\2\2\2&\u01d7\3\2\2\2(\u01e4\3\2\2\2*\u01e9\3\2\2\2,\u01eb\3"+
		"\2\2\2.\u01f0\3\2\2\2\60\u01fc\3\2\2\2\62\u0204\3\2\2\2\64\u0208\3\2\2"+
		"\2\66\u020a\3\2\2\28\u021a\3\2\2\2:\u021c\3\2\2\2<\u021e\3\2\2\2>\u0226"+
		"\3\2\2\2@\u022e\3\2\2\2B\u0236\3\2\2\2D\u023e\3\2\2\2F\u0246\3\2\2\2H"+
		"\u0252\3\2\2\2J\u0254\3\2\2\2L\u025c\3\2\2\2N\u025e\3\2\2\2P\u0260\3\2"+
		"\2\2R\u026a\3\2\2\2T\u026c\3\2\2\2V\u0271\3\2\2\2X\u0276\3\2\2\2Z\u0281"+
		"\3\2\2\2\\\u0287\3\2\2\2^\u028c\3\2\2\2`\u028e\3\2\2\2b\u0298\3\2\2\2"+
		"d\u029a\3\2\2\2f\u029c\3\2\2\2h\u02a2\3\2\2\2j\u02a6\3\2\2\2l\u02ab\3"+
		"\2\2\2n\u02ad\3\2\2\2p\u02af\3\2\2\2r\u02b1\3\2\2\2t\u02b7\3\2\2\2v\u02b9"+
		"\3\2\2\2x\u02bc\3\2\2\2z\u02bf\3\2\2\2|\u02c3\3\2\2\2~\u02c5\3\2\2\2\u0080"+
		"\u02c7\3\2\2\2\u0082\u02c9\3\2\2\2\u0084\u02cb\3\2\2\2\u0086\u02cd\3\2"+
		"\2\2\u0088\u02cf\3\2\2\2\u008a\u02d6\3\2\2\2\u008c\u02da\3\2\2\2\u008e"+
		"\u02de\3\2\2\2\u0090\u02ed\3\2\2\2\u0092\u02f0\3\2\2\2\u0094\u02f5\3\2"+
		"\2\2\u0096\u0302\3\2\2\2\u0098\u0304\3\2\2\2\u009a\u0307\3\2\2\2\u009c"+
		"\u0314\3\2\2\2\u009e\u0322\3\2\2\2\u00a0\u032a\3\2\2\2\u00a2\u0332\3\2"+
		"\2\2\u00a4\u0334\3\2\2\2\u00a6\u033a\3\2\2\2\u00a8\u0340\3\2\2\2\u00aa"+
		"\u0342\3\2\2\2\u00ac\u034e\3\2\2\2\u00ae\u0359\3\2\2\2\u00b0\u035d\3\2"+
		"\2\2\u00b2\u036c\3\2\2\2\u00b4\u036e\3\2\2\2\u00b6\u0372\3\2\2\2\u00b8"+
		"\u0374\3\2\2\2\u00ba\u0380\3\2\2\2\u00bc\u0390\3\2\2\2\u00be\u0392\3\2"+
		"\2\2\u00c0\u0399\3\2\2\2\u00c2\u039b\3\2\2\2\u00c4\u03a1\3\2\2\2\u00c6"+
		"\u03a3\3\2\2\2\u00c8\u03a9\3\2\2\2\u00ca\u03ab\3\2\2\2\u00cc\u03af\3\2"+
		"\2\2\u00ce\u03b3\3\2\2\2\u00d0\u03c3\3\2\2\2\u00d2\u03c5\3\2\2\2\u00d4"+
		"\u03d4\3\2\2\2\u00d6\u03db\3\2\2\2\u00d8\u03dd\3\2\2\2\u00da\u03e0\3\2"+
		"\2\2\u00dc\u03e3\3\2\2\2\u00de\u03f0\3\2\2\2\u00e0\u03f2\3\2\2\2\u00e2"+
		"\u03f5\3\2\2\2\u00e4\u03fa\3\2\2\2\u00e6\u0402\3\2\2\2\u00e8\u040b\3\2"+
		"\2\2\u00ea\u0411\3\2\2\2\u00ec\u0426\3\2\2\2\u00ee\u0428\3\2\2\2\u00f0"+
		"\u042e\3\2\2\2\u00f2\u0430\3\2\2\2\u00f4\u0437\3\2\2\2\u00f6\u043b\3\2"+
		"\2\2\u00f8\u043f\3\2\2\2\u00fa\u0443\3\2\2\2\u00fc\u0446\3\2\2\2\u00fe"+
		"\u0453\3\2\2\2\u0100\u0456\3\2\2\2\u0102\u0459\3\2\2\2\u0104\u0469\3\2"+
		"\2\2\u0106\u046b\3\2\2\2\u0108\u0475\3\2\2\2\u010a\u0482\3\2\2\2\u010c"+
		"\u0485\3\2\2\2\u010e\u048a\3\2\2\2\u0110\u0497\3\2\2\2\u0112\u04a2\3\2"+
		"\2\2\u0114\u04a8\3\2\2\2\u0116\u04aa\3\2\2\2\u0118\u011a\5\u00c6d\2\u0119"+
		"\u0118\3\2\2\2\u011a\u011d\3\2\2\2\u011b\u0119\3\2\2\2\u011b\u011c\3\2"+
		"\2\2\u011c\u011f\3\2\2\2\u011d\u011b\3\2\2\2\u011e\u0120\5\4\3\2\u011f"+
		"\u011e\3\2\2\2\u0120\u0121\3\2\2\2\u0121\u011f\3\2\2\2\u0121\u0122\3\2"+
		"\2\2\u0122\3\3\2\2\2\u0123\u0124\5R*\2\u0124\u0125\7\16\2\2\u0125\u0147"+
		"\3\2\2\2\u0126\u0127\5\66\34\2\u0127\u0128\7\16\2\2\u0128\u0147\3\2\2"+
		"\2\u0129\u012a\5\u00aaV\2\u012a\u012b\7\16\2\2\u012b\u0147\3\2\2\2\u012c"+
		"\u012d\5\b\5\2\u012d\u012e\7\16\2\2\u012e\u0147\3\2\2\2\u012f\u0130\5"+
		"\6\4\2\u0130\u0131\7\16\2\2\u0131\u0147\3\2\2\2\u0132\u0133\5\32\16\2"+
		"\u0133\u0134\7\16\2\2\u0134\u0147\3\2\2\2\u0135\u0136\5\u00caf\2\u0136"+
		"\u0137\7\16\2\2\u0137\u0147\3\2\2\2\u0138\u0139\5\u00ccg\2\u0139\u013a"+
		"\7\16\2\2\u013a\u0147\3\2\2\2\u013b\u013c\5\u010a\u0086\2\u013c\u013d"+
		"\7\16\2\2\u013d\u0147\3\2\2\2\u013e\u013f\5\u00dep\2\u013f\u0140\7\16"+
		"\2\2\u0140\u0147\3\2\2\2\u0141\u0142\5\u00fa~\2\u0142\u0143\7\16\2\2\u0143"+
		"\u0147\3\2\2\2\u0144\u0147\5\u0114\u008b\2\u0145\u0147\5\u0116\u008c\2"+
		"\u0146\u0123\3\2\2\2\u0146\u0126\3\2\2\2\u0146\u0129\3\2\2\2\u0146\u012c"+
		"\3\2\2\2\u0146\u012f\3\2\2\2\u0146\u0132\3\2\2\2\u0146\u0135\3\2\2\2\u0146"+
		"\u0138\3\2\2\2\u0146\u013b\3\2\2\2\u0146\u013e\3\2\2\2\u0146\u0141\3\2"+
		"\2\2\u0146\u0144\3\2\2\2\u0146\u0145\3\2\2\2\u0147\5\3\2\2\2\u0148\u0149"+
		"\7M\2\2\u0149\u014a\7f\2\2\u014a\u014c\7\21\2\2\u014b\u014d\5\4\3\2\u014c"+
		"\u014b\3\2\2\2\u014d\u014e\3\2\2\2\u014e\u014c\3\2\2\2\u014e\u014f\3\2"+
		"\2\2\u014f\u0150\3\2\2\2\u0150\u0151\7\22\2\2\u0151\7\3\2\2\2\u0152\u0155"+
		"\5\n\6\2\u0153\u0155\5\f\7\2\u0154\u0152\3\2\2\2\u0154\u0153\3\2\2\2\u0155"+
		"\t\3\2\2\2\u0156\u0157\5\16\b\2\u0157\u0158\7\21\2\2\u0158\u0159\5\20"+
		"\t\2\u0159\u015a\7\22\2\2\u015a\13\3\2\2\2\u015b\u015d\t\2\2\2\u015c\u015b"+
		"\3\2\2\2\u015c\u015d\3\2\2\2\u015d\u015e\3\2\2\2\u015e\u015f\7d\2\2\u015f"+
		"\u0160\7f\2\2\u0160\r\3\2\2\2\u0161\u0163\t\2\2\2\u0162\u0161\3\2\2\2"+
		"\u0162\u0163\3\2\2\2\u0163\u0164\3\2\2\2\u0164\u0165\7d\2\2\u0165\u0167"+
		"\7f\2\2\u0166\u0168\5\24\13\2\u0167\u0166\3\2\2\2\u0167\u0168\3\2\2\2"+
		"\u0168\17\3\2\2\2\u0169\u016b\5\22\n\2\u016a\u0169\3\2\2\2\u016b\u016e"+
		"\3\2\2\2\u016c\u016a\3\2\2\2\u016c\u016d\3\2\2\2\u016d\21\3\2\2\2\u016e"+
		"\u016c\3\2\2\2\u016f\u0170\5R*\2\u0170\u0171\7\16\2\2\u0171\u0186\3\2"+
		"\2\2\u0172\u0173\5\66\34\2\u0173\u0174\7\16\2\2\u0174\u0186\3\2\2\2\u0175"+
		"\u0176\5\u00aaV\2\u0176\u0177\7\16\2\2\u0177\u0186\3\2\2\2\u0178\u0179"+
		"\5\u00a8U\2\u0179\u017a\7\16\2\2\u017a\u0186\3\2\2\2\u017b\u017c\5\u00ac"+
		"W\2\u017c\u017d\7\16\2\2\u017d\u0186\3\2\2\2\u017e\u017f\5\u00caf\2\u017f"+
		"\u0180\7\16\2\2\u0180\u0186\3\2\2\2\u0181\u0182\5\u00ccg\2\u0182\u0183"+
		"\7\16\2\2\u0183\u0186\3\2\2\2\u0184\u0186\5\u0114\u008b\2\u0185\u016f"+
		"\3\2\2\2\u0185\u0172\3\2\2\2\u0185\u0175\3\2\2\2\u0185\u0178\3\2\2\2\u0185"+
		"\u017b\3\2\2\2\u0185\u017e\3\2\2\2\u0185\u0181\3\2\2\2\u0185\u0184\3\2"+
		"\2\2\u0186\23\3\2\2\2\u0187\u0188\7\17\2\2\u0188\u018d\5\26\f\2\u0189"+
		"\u018a\7\20\2\2\u018a\u018c\5\26\f\2\u018b\u0189\3\2\2\2\u018c\u018f\3"+
		"\2\2\2\u018d\u018b\3\2\2\2\u018d\u018e\3\2\2\2\u018e\25\3\2\2\2\u018f"+
		"\u018d\3\2\2\2\u0190\u0191\5\30\r\2\u0191\27\3\2\2\2\u0192\u0194\7$\2"+
		"\2\u0193\u0192\3\2\2\2\u0193\u0194\3\2\2\2\u0194\u0195\3\2\2\2\u0195\u019a"+
		"\7f\2\2\u0196\u0197\7$\2\2\u0197\u0199\7f\2\2\u0198\u0196\3\2\2\2\u0199"+
		"\u019c\3\2\2\2\u019a\u0198\3\2\2\2\u019a\u019b\3\2\2\2\u019b\31\3\2\2"+
		"\2\u019c\u019a\3\2\2\2\u019d\u01a2\5\"\22\2\u019e\u01a2\5 \21\2\u019f"+
		"\u01a2\5\36\20\2\u01a0\u01a2\5\34\17\2\u01a1\u019d\3\2\2\2\u01a1\u019e"+
		"\3\2\2\2\u01a1\u019f\3\2\2\2\u01a1\u01a0\3\2\2\2\u01a2\33\3\2\2\2\u01a3"+
		"\u01a5\7Z\2\2\u01a4\u01a3\3\2\2\2\u01a4\u01a5\3\2\2\2\u01a5\u01a6\3\2"+
		"\2\2\u01a6\u01a7\7K\2\2\u01a7\u01a8\7f\2\2\u01a8\35\3\2\2\2\u01a9\u01aa"+
		"\7K\2\2\u01aa\u01ab\7f\2\2\u01ab\u01ac\5V,\2\u01ac\37\3\2\2\2\u01ad\u01ae"+
		"\7Z\2\2\u01ae\u01af\7K\2\2\u01af\u01b0\7f\2\2\u01b0\u01b1\5&\24\2\u01b1"+
		"\u01b5\7\21\2\2\u01b2\u01b4\5\22\n\2\u01b3\u01b2\3\2\2\2\u01b4\u01b7\3"+
		"\2\2\2\u01b5\u01b3\3\2\2\2\u01b5\u01b6\3\2\2\2\u01b6\u01b8\3\2\2\2\u01b7"+
		"\u01b5\3\2\2\2\u01b8\u01b9\7\22\2\2\u01b9!\3\2\2\2\u01ba\u01bb\5$\23\2"+
		"\u01bb\u01bf\7\21\2\2\u01bc\u01be\5*\26\2\u01bd\u01bc\3\2\2\2\u01be\u01c1"+
		"\3\2\2\2\u01bf\u01bd\3\2\2\2\u01bf\u01c0\3\2\2\2\u01c0\u01c2\3\2\2\2\u01c1"+
		"\u01bf\3\2\2\2\u01c2\u01c3\7\22\2\2\u01c3#\3\2\2\2\u01c4\u01c6\7\60\2"+
		"\2\u01c5\u01c4\3\2\2\2\u01c5\u01c6\3\2\2\2\u01c6\u01c7\3\2\2\2\u01c7\u01c8"+
		"\7K\2\2\u01c8\u01c9\7f\2\2\u01c9\u01ca\5&\24\2\u01ca%\3\2\2\2\u01cb\u01cd"+
		"\7\17\2\2\u01cc\u01ce\7O\2\2\u01cd\u01cc\3\2\2\2\u01cd\u01ce\3\2\2\2\u01ce"+
		"\u01cf\3\2\2\2\u01cf\u01d4\5(\25\2\u01d0\u01d1\7\20\2\2\u01d1\u01d3\5"+
		"(\25\2\u01d2\u01d0\3\2\2\2\u01d3\u01d6\3\2\2\2\u01d4\u01d2\3\2\2\2\u01d4"+
		"\u01d5\3\2\2\2\u01d5\u01d8\3\2\2\2\u01d6\u01d4\3\2\2\2\u01d7\u01cb\3\2"+
		"\2\2\u01d7\u01d8\3\2\2\2\u01d8\u01e2\3\2\2\2\u01d9\u01da\7L\2\2\u01da"+
		"\u01df\5\26\f\2\u01db\u01dc\7\20\2\2\u01dc\u01de\5\26\f\2\u01dd\u01db"+
		"\3\2\2\2\u01de\u01e1\3\2\2\2\u01df\u01dd\3\2\2\2\u01df\u01e0\3\2\2\2\u01e0"+
		"\u01e3\3\2\2\2\u01e1\u01df\3\2\2\2\u01e2\u01d9\3\2\2\2\u01e2\u01e3\3\2"+
		"\2\2\u01e3\'\3\2\2\2\u01e4\u01e5\5\30\r\2\u01e5)\3\2\2\2\u01e6\u01ea\5"+
		"\22\n\2\u01e7\u01ea\5,\27\2\u01e8\u01ea\5.\30\2\u01e9\u01e6\3\2\2\2\u01e9"+
		"\u01e7\3\2\2\2\u01e9\u01e8\3\2\2\2\u01ea+\3\2\2\2\u01eb\u01ec\t\3\2\2"+
		"\u01ec\u01ed\5V,\2\u01ed\u01ee\5`\61\2\u01ee\u01ef\7\16\2\2\u01ef-\3\2"+
		"\2\2\u01f0\u01f1\7F\2\2\u01f1\u01f2\7f\2\2\u01f2\u01f4\7\23\2\2\u01f3"+
		"\u01f5\5\60\31\2\u01f4\u01f3\3\2\2\2\u01f4\u01f5\3\2\2\2\u01f5\u01f6\3"+
		"\2\2\2\u01f6\u01f8\7\24\2\2\u01f7\u01f9\5\u00b8]\2\u01f8\u01f7\3\2\2\2"+
		"\u01f8\u01f9\3\2\2\2\u01f9\u01fa\3\2\2\2\u01fa\u01fb\7\16\2\2\u01fb/\3"+
		"\2\2\2\u01fc\u0201\5\62\32\2\u01fd\u01fe\7\20\2\2\u01fe\u0200\5\62\32"+
		"\2\u01ff\u01fd\3\2\2\2\u0200\u0203\3\2\2\2\u0201\u01ff\3\2\2\2\u0201\u0202"+
		"\3\2\2\2\u0202\61\3\2\2\2\u0203\u0201\3\2\2\2\u0204\u0205\5\64\33\2\u0205"+
		"\u0206\5\u00bc_\2\u0206\u0207\5d\63\2\u0207\63\3\2\2\2\u0208\u0209\7="+
		"\2\2\u0209\65\3\2\2\2\u020a\u020b\7I\2\2\u020b\u020c\58\35\2\u020c\u020d"+
		"\7f\2\2\u020d\u020e\7!\2\2\u020e\u020f\5:\36\2\u020f\67\3\2\2\2\u0210"+
		"\u021b\5j\66\2\u0211\u021b\5|?\2\u0212\u021b\5~@\2\u0213\u021b\5\u0080"+
		"A\2\u0214\u021b\5h\65\2\u0215\u021b\5\u00a0Q\2\u0216\u021b\5\u00a2R\2"+
		"\u0217\u021b\5\u00c0a\2\u0218\u021b\5\30\r\2\u0219\u021b\5\u0082B\2\u021a"+
		"\u0210\3\2\2\2\u021a\u0211\3\2\2\2\u021a\u0212\3\2\2\2\u021a\u0213\3\2"+
		"\2\2\u021a\u0214\3\2\2\2\u021a\u0215\3\2\2\2\u021a\u0216\3\2\2\2\u021a"+
		"\u0217\3\2\2\2\u021a\u0218\3\2\2\2\u021a\u0219\3\2\2\2\u021b9\3\2\2\2"+
		"\u021c\u021d\5<\37\2\u021d;\3\2\2\2\u021e\u0223\5> \2\u021f\u0220\7 \2"+
		"\2\u0220\u0222\5> \2\u0221\u021f\3\2\2\2\u0222\u0225\3\2\2\2\u0223\u0221"+
		"\3\2\2\2\u0223\u0224\3\2\2\2\u0224=\3\2\2\2\u0225\u0223\3\2\2\2\u0226"+
		"\u022b\5@!\2\u0227\u0228\7\36\2\2\u0228\u022a\5@!\2\u0229\u0227\3\2\2"+
		"\2\u022a\u022d\3\2\2\2\u022b\u0229\3\2\2\2\u022b\u022c\3\2\2\2\u022c?"+
		"\3\2\2\2\u022d\u022b\3\2\2\2\u022e\u0233\5B\"\2\u022f\u0230\7\37\2\2\u0230"+
		"\u0232\5B\"\2\u0231\u022f\3\2\2\2\u0232\u0235\3\2\2\2\u0233\u0231\3\2"+
		"\2\2\u0233\u0234\3\2\2\2\u0234A\3\2\2\2\u0235\u0233\3\2\2\2\u0236\u023b"+
		"\5D#\2\u0237\u0238\t\4\2\2\u0238\u023a\5D#\2\u0239\u0237\3\2\2\2\u023a"+
		"\u023d\3\2\2\2\u023b\u0239\3\2\2\2\u023b\u023c\3\2\2\2\u023cC\3\2\2\2"+
		"\u023d\u023b\3\2\2\2\u023e\u0243\5F$\2\u023f\u0240\t\5\2\2\u0240\u0242"+
		"\5F$\2\u0241\u023f\3\2\2\2\u0242\u0245\3\2\2\2\u0243\u0241\3\2\2\2\u0243"+
		"\u0244\3\2\2\2\u0244E\3\2\2\2\u0245\u0243\3\2\2\2\u0246\u024b\5H%\2\u0247"+
		"\u0248\t\6\2\2\u0248\u024a\5H%\2\u0249\u0247\3\2\2\2\u024a\u024d\3\2\2"+
		"\2\u024b\u0249\3\2\2\2\u024b\u024c\3\2\2\2\u024cG\3\2\2\2\u024d\u024b"+
		"\3\2\2\2\u024e\u024f\5J&\2\u024f\u0250\5L\'\2\u0250\u0253\3\2\2\2\u0251"+
		"\u0253\5L\'\2\u0252\u024e\3\2\2\2\u0252\u0251\3\2\2\2\u0253I\3\2\2\2\u0254"+
		"\u0255\t\7\2\2\u0255K\3\2\2\2\u0256\u025d\5\30\r\2\u0257\u025d\5N(\2\u0258"+
		"\u0259\7\23\2\2\u0259\u025a\5:\36\2\u025a\u025b\7\24\2\2\u025b\u025d\3"+
		"\2\2\2\u025c\u0256\3\2\2\2\u025c\u0257\3\2\2\2\u025c\u0258\3\2\2\2\u025d"+
		"M\3\2\2\2\u025e\u025f\t\b\2\2\u025fO\3\2\2\2\u0260\u0261\5:\36\2\u0261"+
		"Q\3\2\2\2\u0262\u0263\7-\2\2\u0263\u026b\5T+\2\u0264\u026b\5\u0088E\2"+
		"\u0265\u026b\5\u008eH\2\u0266\u026b\5\u009aN\2\u0267\u0268\7\65\2\2\u0268"+
		"\u026b\5d\63\2\u0269\u026b\5\u00c4c\2\u026a\u0262\3\2\2\2\u026a\u0264"+
		"\3\2\2\2\u026a\u0265\3\2\2\2\u026a\u0266\3\2\2\2\u026a\u0267\3\2\2\2\u026a"+
		"\u0269\3\2\2\2\u026bS\3\2\2\2\u026c\u026d\5V,\2\u026d\u026e\5`\61\2\u026e"+
		"U\3\2\2\2\u026f\u0272\5X-\2\u0270\u0272\5^\60\2\u0271\u026f\3\2\2\2\u0271"+
		"\u0270\3\2\2\2\u0272W\3\2\2\2\u0273\u0277\5Z.\2\u0274\u0277\5\\/\2\u0275"+
		"\u0277\5\30\r\2\u0276\u0273\3\2\2\2\u0276\u0274\3\2\2\2\u0276\u0275\3"+
		"\2\2\2\u0277Y\3\2\2\2\u0278\u0282\5h\65\2\u0279\u0282\5j\66\2\u027a\u0282"+
		"\5|?\2\u027b\u0282\5~@\2\u027c\u0282\5\u0080A\2\u027d\u0282\5\u0082B\2"+
		"\u027e\u0282\5\u0084C\2\u027f\u0282\5\u0086D\2\u0280\u0282\5\u00c2b\2"+
		"\u0281\u0278\3\2\2\2\u0281\u0279\3\2\2\2\u0281\u027a\3\2\2\2\u0281\u027b"+
		"\3\2\2\2\u0281\u027c\3\2\2\2\u0281\u027d\3\2\2\2\u0281\u027e\3\2\2\2\u0281"+
		"\u027f\3\2\2\2\u0281\u0280\3\2\2\2\u0282[\3\2\2\2\u0283\u0288\5\u009e"+
		"P\2\u0284\u0288\5\u00a0Q\2\u0285\u0288\5\u00a2R\2\u0286\u0288\5\u00be"+
		"`\2\u0287\u0283\3\2\2\2\u0287\u0284\3\2\2\2\u0287\u0285\3\2\2\2\u0287"+
		"\u0286\3\2\2\2\u0288]\3\2\2\2\u0289\u028d\5\u0088E\2\u028a\u028d\5\u008e"+
		"H\2\u028b\u028d\5\u009aN\2\u028c\u0289\3\2\2\2\u028c\u028a\3\2\2\2\u028c"+
		"\u028b\3\2\2\2\u028d_\3\2\2\2\u028e\u0293\5b\62\2\u028f\u0290\7\20\2\2"+
		"\u0290\u0292\5b\62\2\u0291\u028f\3\2\2\2\u0292\u0295\3\2\2\2\u0293\u0291"+
		"\3\2\2\2\u0293\u0294\3\2\2\2\u0294a\3\2\2\2\u0295\u0293\3\2\2\2\u0296"+
		"\u0299\5d\63\2\u0297\u0299\5f\64\2\u0298\u0296\3\2\2\2\u0298\u0297\3\2"+
		"\2\2\u0299c\3\2\2\2\u029a\u029b\7f\2\2\u029be\3\2\2\2\u029c\u029d\5\u00a4"+
		"S\2\u029dg\3\2\2\2\u029e\u02a3\7W\2\2\u029f\u02a3\7^\2\2\u02a0\u02a1\7"+
		"A\2\2\u02a1\u02a3\7^\2\2\u02a2\u029e\3\2\2\2\u02a2\u029f\3\2\2\2\u02a2"+
		"\u02a0\3\2\2\2\u02a3i\3\2\2\2\u02a4\u02a7\5l\67\2\u02a5\u02a7\5t;\2\u02a6"+
		"\u02a4\3\2\2\2\u02a6\u02a5\3\2\2\2\u02a7k\3\2\2\2\u02a8\u02ac\5n8\2\u02a9"+
		"\u02ac\5p9\2\u02aa\u02ac\5r:\2\u02ab\u02a8\3\2\2\2\u02ab\u02a9\3\2\2\2"+
		"\u02ab\u02aa\3\2\2\2\u02acm\3\2\2\2\u02ad\u02ae\7@\2\2\u02aeo\3\2\2\2"+
		"\u02af\u02b0\7A\2\2\u02b0q\3\2\2\2\u02b1\u02b2\7A\2\2\u02b2\u02b3\7A\2"+
		"\2\u02b3s\3\2\2\2\u02b4\u02b8\5v<\2\u02b5\u02b8\5x=\2\u02b6\u02b8\5z>"+
		"\2\u02b7\u02b4\3\2\2\2\u02b7\u02b5\3\2\2\2\u02b7\u02b6\3\2\2\2\u02b8u"+
		"\3\2\2\2\u02b9\u02ba\7P\2\2\u02ba\u02bb\7@\2\2\u02bbw\3\2\2\2\u02bc\u02bd"+
		"\7P\2\2\u02bd\u02be\7A\2\2\u02bey\3\2\2\2\u02bf\u02c0\7P\2\2\u02c0\u02c1"+
		"\7A\2\2\u02c1\u02c2\7A\2\2\u02c2{\3\2\2\2\u02c3\u02c4\7U\2\2\u02c4}\3"+
		"\2\2\2\u02c5\u02c6\7<\2\2\u02c6\177\3\2\2\2\u02c7\u02c8\7X\2\2\u02c8\u0081"+
		"\3\2\2\2\u02c9\u02ca\7\61\2\2\u02ca\u0083\3\2\2\2\u02cb\u02cc\7T\2\2\u02cc"+
		"\u0085\3\2\2\2\u02cd\u02ce\7N\2\2\u02ce\u0087\3\2\2\2\u02cf\u02d0\7\64"+
		"\2\2\u02d0\u02d1\7f\2\2\u02d1\u02d2\7\21\2\2\u02d2\u02d3\5\u008aF\2\u02d3"+
		"\u02d4\7\22\2\2\u02d4\u0089\3\2\2\2\u02d5\u02d7\5\u008cG\2\u02d6\u02d5"+
		"\3\2\2\2\u02d7\u02d8\3\2\2\2\u02d8\u02d6\3\2\2\2\u02d8\u02d9\3\2\2\2\u02d9"+
		"\u008b\3\2\2\2\u02da\u02db\5V,\2\u02db\u02dc\5`\61\2\u02dc\u02dd\7\16"+
		"\2\2\u02dd\u008d\3\2\2\2\u02de\u02df\7R\2\2\u02df\u02e0\7f\2\2\u02e0\u02e1"+
		"\7+\2\2\u02e1\u02e2\7\23\2\2\u02e2\u02e3\5\u0090I\2\u02e3\u02e4\7\24\2"+
		"\2\u02e4\u02e5\7\21\2\2\u02e5\u02e6\5\u0092J\2\u02e6\u02e7\7\22\2\2\u02e7"+
		"\u008f\3\2\2\2\u02e8\u02ee\5j\66\2\u02e9\u02ee\5|?\2\u02ea\u02ee\5\u0080"+
		"A\2\u02eb\u02ee\5\u009aN\2\u02ec\u02ee\5\30\r\2\u02ed\u02e8\3\2\2\2\u02ed"+
		"\u02e9\3\2\2\2\u02ed\u02ea\3\2\2\2\u02ed\u02eb\3\2\2\2\u02ed\u02ec\3\2"+
		"\2\2\u02ee\u0091\3\2\2\2\u02ef\u02f1\5\u0094K\2\u02f0\u02ef\3\2\2\2\u02f1"+
		"\u02f2\3\2\2\2\u02f2\u02f0\3\2\2\2\u02f2\u02f3\3\2\2\2\u02f3\u0093\3\2"+
		"\2\2\u02f4\u02f6\5\u0096L\2\u02f5\u02f4\3\2\2\2\u02f6\u02f7\3\2\2\2\u02f7"+
		"\u02f5\3\2\2\2\u02f7\u02f8\3\2\2\2\u02f8\u02f9\3\2\2\2\u02f9\u02fa\5\u0098"+
		"M\2\u02fa\u02fb\7\16\2\2\u02fb\u0095\3\2\2\2\u02fc\u02fd\7V\2\2\u02fd"+
		"\u02fe\5:\36\2\u02fe\u02ff\7\17\2\2\u02ff\u0303\3\2\2\2\u0300\u0301\7"+
		">\2\2\u0301\u0303\7\17\2\2\u0302\u02fc\3\2\2\2\u0302\u0300\3\2\2\2\u0303"+
		"\u0097\3\2\2\2\u0304\u0305\5V,\2\u0305\u0306\5b\62\2\u0306\u0099\3\2\2"+
		"\2\u0307\u0308\7B\2\2\u0308\u0309\7f\2\2\u0309\u030a\7\21\2\2\u030a\u030f"+
		"\5\u009cO\2\u030b\u030c\7\20\2\2\u030c\u030e\5\u009cO\2\u030d\u030b\3"+
		"\2\2\2\u030e\u0311\3\2\2\2\u030f\u030d\3\2\2\2\u030f\u0310\3\2\2\2\u0310"+
		"\u0312\3\2\2\2\u0311\u030f\3\2\2\2\u0312\u0313\7\22\2\2\u0313\u009b\3"+
		"\2\2\2\u0314\u0315\7f\2\2\u0315\u009d\3\2\2\2\u0316\u0317\7\62\2\2\u0317"+
		"\u0318\7\31\2\2\u0318\u0319\5X-\2\u0319\u031a\7\20\2\2\u031a\u031b\5P"+
		")\2\u031b\u031c\7\32\2\2\u031c\u0323\3\2\2\2\u031d\u031e\7\62\2\2\u031e"+
		"\u031f\7\31\2\2\u031f\u0320\5X-\2\u0320\u0321\7\32\2\2\u0321\u0323\3\2"+
		"\2\2\u0322\u0316\3\2\2\2\u0322\u031d\3\2\2\2\u0323\u009f\3\2\2\2\u0324"+
		"\u0325\7*\2\2\u0325\u0326\7\31\2\2\u0326\u0327\5P)\2\u0327\u0328\7\32"+
		"\2\2\u0328\u032b\3\2\2\2\u0329\u032b\7*\2\2\u032a\u0324\3\2\2\2\u032a"+
		"\u0329\3\2\2\2\u032b\u00a1\3\2\2\2\u032c\u032d\7C\2\2\u032d\u032e\7\31"+
		"\2\2\u032e\u032f\5P)\2\u032f\u0330\7\32\2\2\u0330\u0333\3\2\2\2\u0331"+
		"\u0333\7C\2\2\u0332\u032c\3\2\2\2\u0332\u0331\3\2\2\2\u0333\u00a3\3\2"+
		"\2\2\u0334\u0336\7f\2\2\u0335\u0337\5\u00a6T\2\u0336\u0335\3\2\2\2\u0337"+
		"\u0338\3\2\2\2\u0338\u0336\3\2\2\2\u0338\u0339\3\2\2\2\u0339\u00a5\3\2"+
		"\2\2\u033a\u033b\7\25\2\2\u033b\u033c\5P)\2\u033c\u033d\7\26\2\2\u033d"+
		"\u00a7\3\2\2\2\u033e\u0341\5\u00ceh\2\u033f\u0341\5\u00d2j\2\u0340\u033e"+
		"\3\2\2\2\u0340\u033f\3\2\2\2\u0341\u00a9\3\2\2\2\u0342\u0343\7G\2\2\u0343"+
		"\u0344\7f\2\2\u0344\u0348\7\21\2\2\u0345\u0347\5\u008cG\2\u0346\u0345"+
		"\3\2\2\2\u0347\u034a\3\2\2\2\u0348\u0346\3\2\2\2\u0348\u0349\3\2\2\2\u0349"+
		"\u034b\3\2\2\2\u034a\u0348\3\2\2\2\u034b\u034c\7\22\2\2\u034c\u00ab\3"+
		"\2\2\2\u034d\u034f\5\u00aeX\2\u034e\u034d\3\2\2\2\u034e\u034f\3\2\2\2"+
		"\u034f\u0350\3\2\2\2\u0350\u0351\5\u00b0Y\2\u0351\u0352\7f\2\2\u0352\u0354"+
		"\5\u00b2Z\2\u0353\u0355\5\u00b8]\2\u0354\u0353\3\2\2\2\u0354\u0355\3\2"+
		"\2\2\u0355\u0357\3\2\2\2\u0356\u0358\5\u00ba^\2\u0357\u0356\3\2\2\2\u0357"+
		"\u0358\3\2\2\2\u0358\u00ad\3\2\2\2\u0359\u035a\7S\2\2\u035a\u00af\3\2"+
		"\2\2\u035b\u035e\5\u00bc_\2\u035c\u035e\79\2\2\u035d\u035b\3\2\2\2\u035d"+
		"\u035c\3\2\2\2\u035e\u00b1\3\2\2\2\u035f\u0360\7\23\2\2\u0360\u0365\5"+
		"\u00b4[\2\u0361\u0362\7\20\2\2\u0362\u0364\5\u00b4[\2\u0363\u0361\3\2"+
		"\2\2\u0364\u0367\3\2\2\2\u0365\u0363\3\2\2\2\u0365\u0366\3\2\2\2\u0366"+
		"\u0368\3\2\2\2\u0367\u0365\3\2\2\2\u0368\u0369\7\24\2\2\u0369\u036d\3"+
		"\2\2\2\u036a\u036b\7\23\2\2\u036b\u036d\7\24\2\2\u036c\u035f\3\2\2\2\u036c"+
		"\u036a\3\2\2\2\u036d\u00b3\3\2\2\2\u036e\u036f\5\u00b6\\\2\u036f\u0370"+
		"\5\u00bc_\2\u0370\u0371\5d\63\2\u0371\u00b5\3\2\2\2\u0372\u0373\t\t\2"+
		"\2\u0373\u00b7\3\2\2\2\u0374\u0375\78\2\2\u0375\u0376\7\23\2\2\u0376\u037b"+
		"\5\30\r\2\u0377\u0378\7\20\2\2\u0378\u037a\5\30\r\2\u0379\u0377\3\2\2"+
		"\2\u037a\u037d\3\2\2\2\u037b\u0379\3\2\2\2\u037b\u037c\3\2\2\2\u037c\u037e"+
		"\3\2\2\2\u037d\u037b\3\2\2\2\u037e\u037f\7\24\2\2\u037f\u00b9\3\2\2\2"+
		"\u0380\u0381\7D\2\2\u0381\u0382\7\23\2\2\u0382\u0387\7\f\2\2\u0383\u0384"+
		"\7\20\2\2\u0384\u0386\7\f\2\2\u0385\u0383\3\2\2\2\u0386\u0389\3\2\2\2"+
		"\u0387\u0385\3\2\2\2\u0387\u0388\3\2\2\2\u0388\u038a\3\2\2\2\u0389\u0387"+
		"\3\2\2\2\u038a\u038b\7\24\2\2\u038b\u00bb\3\2\2\2\u038c\u0391\5Z.\2\u038d"+
		"\u0391\5\u00a0Q\2\u038e\u0391\5\u00a2R\2\u038f\u0391\5\30\r\2\u0390\u038c"+
		"\3\2\2\2\u0390\u038d\3\2\2\2\u0390\u038e\3\2\2\2\u0390\u038f\3\2\2\2\u0391"+
		"\u00bd\3\2\2\2\u0392\u0393\7Q\2\2\u0393\u0394\7\31\2\2\u0394\u0395\5P"+
		")\2\u0395\u0396\7\20\2\2\u0396\u0397\5P)\2\u0397\u0398\7\32\2\2\u0398"+
		"\u00bf\3\2\2\2\u0399\u039a\7Q\2\2\u039a\u00c1\3\2\2\2\u039b\u039c\7J\2"+
		"\2\u039c\u00c3\3\2\2\2\u039d\u039e\7\64\2\2\u039e\u03a2\7f\2\2\u039f\u03a0"+
		"\7R\2\2\u03a0\u03a2\7f\2\2\u03a1\u039d\3\2\2\2\u03a1\u039f\3\2\2\2\u03a2"+
		"\u00c5\3\2\2\2\u03a3\u03a4\7\63\2\2\u03a4\u03a5\5\u00c8e\2\u03a5\u03a6"+
		"\7\16\2\2\u03a6\u00c7\3\2\2\2\u03a7\u03aa\5\30\r\2\u03a8\u03aa\7\f\2\2"+
		"\u03a9\u03a7\3\2\2\2\u03a9\u03a8\3\2\2\2\u03aa\u00c9\3\2\2\2\u03ab\u03ac"+
		"\7`\2\2\u03ac\u03ad\5\30\r\2\u03ad\u03ae\7\f\2\2\u03ae\u00cb\3\2\2\2\u03af"+
		"\u03b0\7_\2\2\u03b0\u03b1\5\30\r\2\u03b1\u03b2\7\f\2\2\u03b2\u00cd\3\2"+
		"\2\2\u03b3\u03b4\7\66\2\2\u03b4\u03b5\7a\2\2\u03b5\u03b6\5\u00bc_\2\u03b6"+
		"\u03b7\5\u00d0i\2\u03b7\u00cf\3\2\2\2\u03b8\u03b9\5d\63\2\u03b9\u03ba"+
		"\5\u00b8]\2\u03ba\u03c4\3\2\2\2\u03bb\u03c0\5d\63\2\u03bc\u03bd\7\20\2"+
		"\2\u03bd\u03bf\5d\63\2\u03be\u03bc\3\2\2\2\u03bf\u03c2\3\2\2\2\u03c0\u03be"+
		"\3\2\2\2\u03c0\u03c1\3\2\2\2\u03c1\u03c4\3\2\2\2\u03c2\u03c0\3\2\2\2\u03c3"+
		"\u03b8\3\2\2\2\u03c3\u03bb\3\2\2\2\u03c4\u00d1\3\2\2\2\u03c5\u03c6\7a"+
		"\2\2\u03c6\u03c7\5\u00bc_\2\u03c7\u03c8\5\u00d4k\2\u03c8\u00d3\3\2\2\2"+
		"\u03c9\u03ca\5d\63\2\u03ca\u03cb\5\u00d6l\2\u03cb\u03d5\3\2\2\2\u03cc"+
		"\u03d1\5d\63\2\u03cd\u03ce\7\20\2\2\u03ce\u03d0\5d\63\2\u03cf\u03cd\3"+
		"\2\2\2\u03d0\u03d3\3\2\2\2\u03d1\u03cf\3\2\2\2\u03d1\u03d2\3\2\2\2\u03d2"+
		"\u03d5\3\2\2\2\u03d3\u03d1\3\2\2\2\u03d4\u03c9\3\2\2\2\u03d4\u03cc\3\2"+
		"\2\2\u03d5\u00d5\3\2\2\2\u03d6\u03d8\5\u00d8m\2\u03d7\u03d9\5\u00dan\2"+
		"\u03d8\u03d7\3\2\2\2\u03d8\u03d9\3\2\2\2\u03d9\u03dc\3\2\2\2\u03da\u03dc"+
		"\5\u00dan\2\u03db\u03d6\3\2\2\2\u03db\u03da\3\2\2\2\u03dc\u00d7\3\2\2"+
		"\2\u03dd\u03de\7H\2\2\u03de\u03df\5\u00dco\2\u03df\u00d9\3\2\2\2\u03e0"+
		"\u03e1\7\'\2\2\u03e1\u03e2\5\u00dco\2\u03e2\u00db\3\2\2\2\u03e3\u03e4"+
		"\7\23\2\2\u03e4\u03e9\5\30\r\2\u03e5\u03e6\7\20\2\2\u03e6\u03e8\5\30\r"+
		"\2\u03e7\u03e5\3\2\2\2\u03e8\u03eb\3\2\2\2\u03e9\u03e7\3\2\2\2\u03e9\u03ea"+
		"\3\2\2\2\u03ea\u03ec\3\2\2\2\u03eb\u03e9\3\2\2\2\u03ec\u03ed\7\24\2\2"+
		"\u03ed\u00dd\3\2\2\2\u03ee\u03f1\5\u00e2r\2\u03ef\u03f1\5\u00e0q\2\u03f0"+
		"\u03ee\3\2\2\2\u03f0\u03ef\3\2\2\2\u03f1\u00df\3\2\2\2\u03f2\u03f3\7e"+
		"\2\2\u03f3\u03f4\7f\2\2\u03f4\u00e1\3\2\2\2\u03f5\u03f6\5\u00e4s\2\u03f6"+
		"\u03f7\7\21\2\2\u03f7\u03f8\5\u00eav\2\u03f8\u03f9\7\22\2\2\u03f9\u00e3"+
		"\3\2\2\2\u03fa\u03fb\7e\2\2\u03fb\u03fd\7f\2\2\u03fc\u03fe\5\u00e8u\2"+
		"\u03fd\u03fc\3\2\2\2\u03fd\u03fe\3\2\2\2\u03fe\u0400\3\2\2\2\u03ff\u0401"+
		"\5\u00e6t\2\u0400\u03ff\3\2\2\2\u0400\u0401\3\2\2\2\u0401\u00e5\3\2\2"+
		"\2\u0402\u0403\7L\2\2\u0403\u0408\5\30\r\2\u0404\u0405\7\20\2\2\u0405"+
		"\u0407\5\30\r\2\u0406\u0404\3\2\2\2\u0407\u040a\3\2\2\2\u0408\u0406\3"+
		"\2\2\2\u0408\u0409\3\2\2\2\u0409\u00e7\3\2\2\2\u040a\u0408\3\2\2\2\u040b"+
		"\u040c\7\17\2\2\u040c\u040d\5\30\r\2\u040d\u00e9\3\2\2\2\u040e\u0410\5"+
		"\u00ecw\2\u040f\u040e\3\2\2\2\u0410\u0413\3\2\2\2\u0411\u040f\3\2\2\2"+
		"\u0411\u0412\3\2\2\2\u0412\u00eb\3\2\2\2\u0413\u0411\3\2\2\2\u0414\u0415"+
		"\5\u00eex\2\u0415\u0416\7\16\2\2\u0416\u0427\3\2\2\2\u0417\u0418\5\u00f2"+
		"z\2\u0418\u0419\7\16\2\2\u0419\u0427\3\2\2\2\u041a\u041b\5\u00f4{\2\u041b"+
		"\u041c\7\16\2\2\u041c\u0427\3\2\2\2\u041d\u041e\5\u00f6|\2\u041e\u041f"+
		"\7\16\2\2\u041f\u0427\3\2\2\2\u0420\u0421\5\u00f8}\2\u0421\u0422\7\16"+
		"\2\2\u0422\u0427\3\2\2\2\u0423\u0424\5\u00a8U\2\u0424\u0425\7\16\2\2\u0425"+
		"\u0427\3\2\2\2\u0426\u0414\3\2\2\2\u0426\u0417\3\2\2\2\u0426\u041a\3\2"+
		"\2\2\u0426\u041d\3\2\2\2\u0426\u0420\3\2\2\2\u0426\u0423\3\2\2\2\u0427"+
		"\u00ed\3\2\2\2\u0428\u0429\7\\\2\2\u0429\u042a\5\u00f0y\2\u042a\u042b"+
		"\7f\2\2\u042b\u00ef\3\2\2\2\u042c\u042f\5\30\r\2\u042d\u042f\7N\2\2\u042e"+
		"\u042c\3\2\2\2\u042e\u042d\3\2\2\2\u042f\u00f1\3\2\2\2\u0430\u0432\7."+
		"\2\2\u0431\u0433\7Y\2\2\u0432\u0431\3\2\2\2\u0432\u0433\3\2\2\2\u0433"+
		"\u0434\3\2\2\2\u0434\u0435\5\u00f0y\2\u0435\u0436\7f\2\2\u0436\u00f3\3"+
		"\2\2\2\u0437\u0438\7)\2\2\u0438\u0439\5\30\r\2\u0439\u043a\7f\2\2\u043a"+
		"\u00f5\3\2\2\2\u043b\u043c\7,\2\2\u043c\u043d\5\30\r\2\u043d\u043e\7f"+
		"\2\2\u043e\u00f7\3\2\2\2\u043f\u0440\7]\2\2\u0440\u0441\5\30\r\2\u0441"+
		"\u0442\7f\2\2\u0442\u00f9\3\2\2\2\u0443\u0444\5\u00fc\177\2\u0444\u0445"+
		"\5\u0102\u0082\2\u0445\u00fb\3\2\2\2\u0446\u0447\7E\2\2\u0447\u0449\7"+
		"f\2\2\u0448\u044a\5\u00fe\u0080\2\u0449\u0448\3\2\2\2\u0449\u044a\3\2"+
		"\2\2\u044a\u044c\3\2\2\2\u044b\u044d\5\u00e6t\2\u044c\u044b\3\2\2\2\u044c"+
		"\u044d\3\2\2\2\u044d\u044e\3\2\2\2\u044e\u044f\7c\2\2\u044f\u0451\5\30"+
		"\r\2\u0450\u0452\5\u0100\u0081\2\u0451\u0450\3\2\2\2\u0451\u0452\3\2\2"+
		"\2\u0452\u00fd\3\2\2\2\u0453\u0454\7\17\2\2\u0454\u0455\5\30\r\2\u0455"+
		"\u00ff\3\2\2\2\u0456\u0457\7/\2\2\u0457\u0458\5\30\r\2\u0458\u0101\3\2"+
		"\2\2\u0459\u045d\7\21\2\2\u045a\u045c\5\u0104\u0083\2\u045b\u045a\3\2"+
		"\2\2\u045c\u045f\3\2\2\2\u045d\u045b\3\2\2\2\u045d\u045e\3\2\2\2\u045e"+
		"\u0460\3\2\2\2\u045f\u045d\3\2\2\2\u0460\u0461\7\22\2\2\u0461\u0103\3"+
		"\2\2\2\u0462\u046a\5\22\n\2\u0463\u0464\5\u0106\u0084\2\u0464\u0465\7"+
		"\16\2\2\u0465\u046a\3\2\2\2\u0466\u0467\5\u0108\u0085\2\u0467\u0468\7"+
		"\16\2\2\u0468\u046a\3\2\2\2\u0469\u0462\3\2\2\2\u0469\u0463\3\2\2\2\u0469"+
		"\u0466\3\2\2\2\u046a\u0105\3\2\2\2\u046b\u046c\7F\2\2\u046c\u046d\7f\2"+
		"\2\u046d\u046f\7\23\2\2\u046e\u0470\5\60\31\2\u046f\u046e\3\2\2\2\u046f"+
		"\u0470\3\2\2\2\u0470\u0471\3\2\2\2\u0471\u0473\7\24\2\2\u0472\u0474\5"+
		"\u00b8]\2\u0473\u0472\3\2\2\2\u0473\u0474\3\2\2\2\u0474\u0107\3\2\2\2"+
		"\u0475\u0476\7\67\2\2\u0476\u0477\7f\2\2\u0477\u0479\7\23\2\2\u0478\u047a"+
		"\5\60\31\2\u0479\u0478\3\2\2\2\u0479\u047a\3\2\2\2\u047a\u047b\3\2\2\2"+
		"\u047b\u047d\7\24\2\2\u047c\u047e\5\u00b8]\2\u047d\u047c\3\2\2\2\u047d"+
		"\u047e\3\2\2\2\u047e\u0109\3\2\2\2\u047f\u0483\5\u0110\u0089\2\u0480\u0483"+
		"\5\u010e\u0088\2\u0481\u0483\5\u010c\u0087\2\u0482\u047f\3\2\2\2\u0482"+
		"\u0480\3\2\2\2\u0482\u0481\3\2\2\2\u0483\u010b\3\2\2\2\u0484\u0486\7Z"+
		"\2\2\u0485\u0484\3\2\2\2\u0485\u0486\3\2\2\2\u0486\u0487\3\2\2\2\u0487"+
		"\u0488\7;\2\2\u0488\u0489\7f\2\2\u0489\u010d\3\2\2\2\u048a\u048b\7Z\2"+
		"\2\u048b\u048c\7;\2\2\u048c\u048d\7f\2\2\u048d\u048e\5&\24\2\u048e\u0492"+
		"\7\21\2\2\u048f\u0491\5\22\n\2\u0490\u048f\3\2\2\2\u0491\u0494\3\2\2\2"+
		"\u0492\u0490\3\2\2\2\u0492\u0493\3\2\2\2\u0493\u0495\3\2\2\2\u0494\u0492"+
		"\3\2\2\2\u0495\u0496\7\22\2\2\u0496\u010f\3\2\2\2\u0497\u0498\5\u0112"+
		"\u008a\2\u0498\u049c\7\21\2\2\u0499\u049b\5*\26\2\u049a\u0499\3\2\2\2"+
		"\u049b\u049e\3\2\2\2\u049c\u049a\3\2\2\2\u049c\u049d\3\2\2\2\u049d\u049f"+
		"\3\2\2\2\u049e\u049c\3\2\2\2\u049f\u04a0\7\22\2\2\u04a0\u0111\3\2\2\2"+
		"\u04a1\u04a3\7\60\2\2\u04a2\u04a1\3\2\2\2\u04a2\u04a3\3\2\2\2\u04a3\u04a4"+
		"\3\2\2\2\u04a4\u04a5\7;\2\2\u04a5\u04a6\7f\2\2\u04a6\u04a7\5&\24\2\u04a7"+
		"\u0113\3\2\2\2\u04a8\u04a9\7j\2\2\u04a9\u0115\3\2\2\2\u04aa\u04ab\7\3"+
		"\2\2\u04ab\u0117\3\2\2\2f\u011b\u0121\u0146\u014e\u0154\u015c\u0162\u0167"+
		"\u016c\u0185\u018d\u0193\u019a\u01a1\u01a4\u01b5\u01bf\u01c5\u01cd\u01d4"+
		"\u01d7\u01df\u01e2\u01e9\u01f4\u01f8\u0201\u021a\u0223\u022b\u0233\u023b"+
		"\u0243\u024b\u0252\u025c\u026a\u0271\u0276\u0281\u0287\u028c\u0293\u0298"+
		"\u02a2\u02a6\u02ab\u02b7\u02d8\u02ed\u02f2\u02f7\u0302\u030f\u0322\u032a"+
		"\u0332\u0338\u0340\u0348\u034e\u0354\u0357\u035d\u0365\u036c\u037b\u0387"+
		"\u0390\u03a1\u03a9\u03c0\u03c3\u03d1\u03d4\u03d8\u03db\u03e9\u03f0\u03fd"+
		"\u0400\u0408\u0411\u0426\u042e\u0432\u0449\u044c\u0451\u045d\u0469\u046f"+
		"\u0473\u0479\u047d\u0482\u0485\u0492\u049c\u04a2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
