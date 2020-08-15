#include "asm.h"

static void		add_token(t_parse *parser, t_type type)
{
	t_token token;

	token.content = NULL;
	token.type = type;
	token.row = parser->row;
	token.column = parser->column;
	if (!parser->tokens)
		parser->tokens = ft_quenew(&token, sizeof(t_token *));
	else
		ft_quevadd(parser->tokens, &token, sizeof(t_token));
	if (type == SEPARATOR)
		parser->column++;
	else if (type == COMMAND_NAME)
		parser->column += 5;
	else if (type == COMMAND_COMMENT)
		parser->column += 8;
}

void			pr_gettoken(t_parse *parser, char *line)
{
	if (line[parser->column] == '\n' &&
	((t_token *)ft_quelookup(parser->tokens))->type != NEW_LINE)
	{
		add_token(parser, NEW_LINE);
	}
	else if (line[parser->column] == SEPARATOR_CHAR)
		add_token(parser, SEPARATOR);
	else if (ft_strnstr(line, NAME_CMD_STRING, 5) && !(parser->tokens &&
	((t_token *)ft_quelookup(parser->tokens))->type == COMMAND_NAME))
	{
		add_token(parser, COMMAND_NAME);
	}
	else if (ft_strnstr(line, COMMENT_CMD_STRING, 8) &&
	((t_token *)ft_quelookup(parser->tokens))->type != COMMAND_COMMENT)
		add_token(parser, COMMAND_COMMENT);
	else if (line[parser->column] == '\"')
	{
		add_token(parser, STRING);
		str_parse(parser, line);
	}
}