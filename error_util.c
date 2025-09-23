/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:48:25 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 17:49:35 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//subjecte göre istenmeyen durumlarda Error yazıp programı bitirmeliyiz.
void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
	//return 0; bulunulan fonksiyonu sona erdirir.
	//exit() hangi fonksiyondan çağırıldığı fark etmeksizin tüm programı bitirir. 
}
